/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:00 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/14 04:38:53 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_builtin_exit(char *argv[])
{
	int	status;

	ft_putendl_fd(MSG_EXIT, STDOUT_FILENO);
	if (argv == NULL || argv[0] == NULL || argv[1] == NULL)
		status = g_shell.status;
	else if (argv[2] == NULL)
	{
		if (ms_strisdigit(argv[1]))
			status = ft_atoi(argv[1]);
		else
		{
			ft_putendl_fd(MSG_ARG_NOTNUM, STDERR_FILENO);
			status = 0xff;
		}
	}
	else
	{
		ft_putendl_fd(MSG_ARG_MANY, STDERR_FILENO);
		return (1);
	}
	exit(status);
}
