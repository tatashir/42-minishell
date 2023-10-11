/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:16 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/11 22:47:27 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	search_env_and_unset(char *env_key)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*tmp;

	cur = g_shell.environ;
	prev = NULL;
	while (cur != NULL)
	{
		if (is_same_envkey(cur->content, env_key))
		{
			if (prev == NULL)
				g_shell.environ = cur->next;
			else
				prev->next = cur->next;
			tmp = cur->next;
			ft_lstdelone(cur, &free);
			cur = tmp;
			return ;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

int	builtin_unset(char *argv[])
{
	int	return_status;
	int	i;

	return_status = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (is_validenv(argv[i]) == false)
		{
			printf(MSG_INVAL_ID, "unset", argv[i++]);
			return_status = 1;
			continue ;
		}
		search_env_and_unset(argv[i]);
		i++;
	}
	return (return_status);
}
