/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:37:43 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:54:18 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_and_return(void *malloc_obj)
{
	free(malloc_obj);
	return (NULL);
}

void	*print_err_set_status_return_null(char *str, int status)
{
	if (str != NULL)
		ft_putendl_fd(str, STDERR_FILENO);
	if (status >= 0)
		g_shell.status = status;
	return (NULL);
}

void	init_fd(int fd[2])
{
	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
}

bool	is_directory(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) != 0)
		return (false);
	if (S_ISDIR(buf.st_mode))
		return (true);
	return (false);
}
