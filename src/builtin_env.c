/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:34:55 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:34:55 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(char *argv[])
{
	t_list	*cur;

	if (argv == NULL)
		return (0);
	cur = g_shell.environ;
	while (cur != NULL)
	{
		ft_putendl_fd(cur->content, STDOUT_FILENO);
		cur = cur->next;
	}
	return (0);
}
