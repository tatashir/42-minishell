/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:00 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/09 16:32:28 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(char *argv[])
{
	int	status;

	ft_putendl_fd(MSG_EXIT, STDOUT_FILENO);
	if (argv == NULL || argv[0] == NULL || argv[1] == NULL)
		status = g_shell.status;
	else if (argv[2] == NULL)
	{
		if ()
	}
}