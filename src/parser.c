/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:37:18 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:53:05 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*clear_cmd_and_return_null(t_cmd *head)
{
	t_cmd	*cur;
	t_cmd	*next;

	cur = head;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur->path);
		free(cur->arg);
		free(cur->input);
		free(cur->output);
		free(cur);
		cur = next;
	}
	return (NULL);
}

static bool	parser_chktokenflag(t_token *token)
{
	size_t	idx;

	idx = 0;
	if (token[idx].flag == FLAG_PIPE)
		return (false);
	while (token[idx].str != NULL)
	{
		if (token[idx].flag == 0)
			return (false);
		idx++;
	}
	if (idx > 0 && token[idx - 1].flag == FLAG_PIPE)
		return (false);
	return (true);
}

t_cmd	*parser(t_token *token)
{
	size_t	idx;
	t_cmd	*head;
	t_cmd	*cur;

	g_shell.heredoc_sigint = false;
	if (!parser_chktokenflag(token))
		return (print_err_set_status_return_null(\
				MSG_SYNTAX_ERR, 258));
	idx = 0;
	head = parser_cmdnew(token, &idx);
	if (head == NULL)
		return (NULL);
	cur = head;
	while (token[idx++].flag == FLAG_PIPE)
	{
		cur->next = parser_cmdnew(token, &idx);
		if (cur->next != NULL)
			cur->next->prev = cur;
		cur = cur->next;
		if (cur == NULL)
			return (clear_cmd_and_return_null(head));
	}
	return (head);
}
