/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:40 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 02:48:03 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmdsize(t_cmd *cmd)
{
	int	size;

	size = 0;
	while (cmd != NULL)
	{
		size++;
		cmd = cmd->next;
	}
	return (size);
}

void	exec_cmd(t_cmd *cmd)
{
	int	(*builtin)(char *arg[]);

	if (cmd == NULL)
		return ;
	builtin = builtin_getfunc(cmd->arg[0]);
	if (builtin != NULL && cmdsize(cmd) == 1)
		exec_a_builtin(cmd, builtin);
	else
		exec_in_child_process(cmd);
	clear_cmd_and_return_null(cmd);
}
