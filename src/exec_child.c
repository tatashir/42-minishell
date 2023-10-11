/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:35 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 02:46:08 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_a_cmd_sub(t_cmd *cmd, char **envp)
{
	int		(*builtin)(char *arg[]);

	if (cmd->path[0] == '\0')
	{
		ft_putendl_fd(MSG_NO_CMD, STDERR_FILENO);
		exit(127);
	}
	if (is_directory(cmd->path))
	{
		ft_putendl_fd(MSG_ISDIR, STDERR_FILENO);
		exit(126);
	}
	builtin = builtin_getfunc(cmd->arg[0]);
	if (builtin != NULL)
		exit(builtin(cmd->arg));
	else
	{
		errno = 0;
		execve(cmd->path, cmd->arg, envp);
		if (errno != 0)
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
		if (errno == ENOENT)
			exit(127);
		exit(126);
	}
}

void	\
	exec_a_cmd(t_cmd *cmd, int prev_pipe[2], int now_pipe[2], char **envp)
{
	int		fd[2];

	fd[0] = prev_pipe[0];
	fd[1] = now_pipe[1];
	if (fd_last_fd(cmd->input) > 0)
		fd[0] = fd_last_fd(cmd->input);
	if (fd_last_fd(cmd->output) > 0)
		fd[1] = fd_last_fd(cmd->output);
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		fd_close(fd);
		fd_close(prev_pipe);
		fd_close(now_pipe);
		exec_a_cmd_sub(cmd, envp);
	}
}

void	handle_status(int status)
{
	if (WIFEXITED(status) && g_shell.kill_child == false)
		g_shell.status = WEXITSTATUS(status);
	else
		return ;
}

void	wait_all(t_cmd *cmd_lst)
{
	int		status;
	t_cmd	*now_cmd;

	now_cmd = cmd_lst;
	while (now_cmd != NULL)
	{
		waitpid(now_cmd->pid, &status, 0);
		handle_status(status);
		now_cmd = now_cmd->next;
	}
	g_shell.kill_child = false;
	fd_close_all_cmd(cmd_lst);
	return ;
}

void	exec_in_child_process(t_cmd *cmd)
{
	int		prev_pipe[2];
	int		now_pipe[2];
	t_cmd	*now_cmd;
	char	**envp;

	envp = map_lst2map(g_shell.environ);
	if (envp == NULL)
		return ;
	init_fd(prev_pipe);
	now_cmd = cmd;
	while (now_cmd != NULL)
	{
		if (now_cmd->next != NULL)
			pipe(now_pipe);
		else
			init_fd(now_pipe);
		exec_a_cmd(now_cmd, prev_pipe, now_pipe, envp);
		fd_close(prev_pipe);
		fd_copy(prev_pipe, now_pipe);
		now_cmd = now_cmd->next;
	}
	free(envp);
	return (wait_all(cmd));
}
