/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:27 by tatashir          #+#    #+#             */
/*   Updated: 2023/09/12 01:11:38 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_a_builtin(t_cmd *cmd, int (*builtin)(char *arg[]))
{
	int	tmp_fd[2];
	int	use_fd[2];

	tmp_fd[0] = dup(STDIN_FILENO);
	tmp_fd[1] = dup(STDOUT_FILENO);
	use_fd[0] = fd_last_fd(cmd->input);
	use_fd[1] = fd_last_fd(cmd->output);
	if (use_fd[0] > STDIN_FILENO)
		dup2(use_fd[0], STDIN_FILENO);
	if (use_fd[1] >= STDIN_FILENO && use_fd[1] != STDOUT_FILENO)
		dup2(use_fd[1], STDOUT_FILENO);
	g_shell.status = builtin(cmd->arg);
	fd_close_all_cmd(cmd);
	dup2(tmp_fd[0], STDIN_FILENO);
	dup2(tmp_fd[1], STDOUT_FILENO);
	fd_close(tmp_fd);
}

int	(*builtin_getfunc(char *arg))(char *argv[])
{
	if (ft_strcmp(arg, "echo") == 0)
		return (builtin_echo);
	else if (ft_strcmp(arg, "cd") == 0)
		return (builtin_cd);
	else if (ft_strcmp(arg, "pwd") == 0)
		return (builtin_pwd);
	else if (ft_strcmp(arg, "export") == 0)
		return (builtin_export);
	else if (ft_strcmp(arg, "unset") == 0)
		return (builtin_unset);
	else if (ft_strcmp(arg, "env") == 0)
		return (builtin_env);
	else if (ft_strcmp(arg, "exit") == 0)
		return (builtin_exit);
	return (0);
}
