/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:53 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/11 23:19:26 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

static t_list	*ms_tlst_from_strlst(char *envp[])
{
	t_list	head;
	t_list	*cur;
	char	*content;
	size_t	i;

	head.next = NULL;
	cur = &head;
	i = 0;
	while (envp[i] != NULL)
	{
		content = ft_strdup(envp[i]);
		if (content == NULL)
			exit(EXIT_FAILURE);
		cur->next = ft_lstnew(content);
		if (cur->next == NULL)
			exit(EXIT_FAILURE);
		cur = cur->next;
		i++;
	}
	return (head.next);
}

void	init_global(char *envp[])
{
	g_shell.environ = ms_tlst_from_strlst(envp);
	g_shell.status = 0;
	g_shell.cmd = NULL;
	g_shell.kill_child = false;
	g_shell.heredoc_sigint = false;
}
