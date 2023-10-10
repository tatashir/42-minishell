/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:44 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/10 19:49:16 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_close(int fd[2])
{
	if (fd[0] != STDIN_FILENO)
		close(fd[0]);
	if (fd[1] != STDOUT_FILENO)
		close(fd[1]);
}

void	ft_copy(int dest[2], int src[2])
{
	dest[0] = src[0];
	dest[1] = src[1];
}

int	fd_last_fd(t_fd *fd_lst)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = -1;
	while (fd_lst[i].path != NULL)
	{
		fd = fd_lst[i].fd;
		i++;
	}
	return (fd);
}

void	fd_close_all_cmd(t_cmd *cmd)
{
	t_cmd	*cur;

	cur = cmd;
	while (cur != NULL)
	{
		fd_close_fds(cur->input);
		fd_close_fds(cur->output);
		cur = cur->next;
	}
}

void	fd_close_fds(t_fd *fd)
{
	size_t	i;

	i = 0;
	while (fd[i].path != NULL)
	{
		if (STDERR_FILENO < fd[i].fd)
			close(fd[i].fd);
		i++;
	}
}
