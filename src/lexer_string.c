/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:36:10 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:03:02 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lexer_string_quote(char *line, size_t *pos, t_list **head)
{
	size_t	stride;

	stride = lexer_tokenlen_quoted(&line[*pos]);
	errno = 0;
	if (stride > LEN_QUOTE_CLOSED)
	{
		lexer_string_lstadd_back_substr(head, line, *pos + 1, stride - 2);
		if (errno == ENOMEM)
			exit(EXIT_FAILURE);
	}
	else if (stride == LEN_QUOTE_CLOSED)
	{
		ft_lstadd_back(head, ft_lstnew(ft_strdup(STR_EMPTY)));
		if (errno == ENOMEM)
			exit(EXIT_FAILURE);
	}
	else if (stride == LEN_QUOTE_UNCLOSED)
	{
		ft_lstadd_back(head, ft_lstnew(ft_strdup(STR_QUOTE)));
		if (errno == ENOMEM)
			exit(EXIT_FAILURE);
	}
	*pos += stride;
}

static void	lexer_string_dquote(char *line, size_t *pos, t_list **head)
{
	size_t	stride;

	stride = lexer_tokenlen_quoted(&line[*pos]);
	errno = 0;
	if (stride > LEN_QUOTE_CLOSED)
	{
		ft_lstadd_back(head, \
				expand_envvar_dquote(&line[*pos + 1], stride - 2));
		if (errno == ENOMEM)
			exit(EXIT_FAILURE);
	}
	else if (stride == LEN_QUOTE_CLOSED)
	{
		ft_lstadd_back(head, ft_lstnew(ft_strdup(STR_EMPTY)));
		if (errno == ENOMEM)
			exit(EXIT_FAILURE);
	}
	else if (stride == LEN_QUOTE_UNCLOSED)
	{
		ft_lstadd_back(head, ft_lstnew(ft_strdup(STR_DQUOTE)));
		if (errno == ENOMEM)
			exit(EXIT_FAILURE);
	}
	*pos += stride;
}

static void	lexer_string_dollar(char *line, size_t *pos, t_list **head)
{
	errno = 0;
	ft_lstadd_back(head, \
		expand_envvar(line, pos, ft_strlen(&line[*pos])));
	if (errno == ENOMEM)
		exit(EXIT_FAILURE);
}

static void	lexer_string_plain(char *line, size_t *pos, t_list **head)
{
	size_t	stride;

	stride = lexer_tokenlen_plain(&line[*pos]);
	if (stride > 0)
	{
		errno = 0;
		lexer_string_lstadd_back_substr(head, line, *pos, stride);
		if (errno == ENOMEM)
			exit(EXIT_FAILURE);
	}
	*pos += stride;
}

char	*lexer_string(char *line)
{
	size_t		pos;
	t_list		*head;
	char		*expand_str;

	pos = 0;
	head = NULL;
	while (line[pos])
	{
		if (line[pos] == CHRS_QUOTE[2])
			lexer_string_quote(line, &pos, &head);
		else if (line[pos] == CHRS_QUOTE[1])
			lexer_string_dquote(line, &pos, &head);
		else if (line[pos] == CHRS_QUOTE[0])
			lexer_string_dollar(line, &pos, &head);
		else
			lexer_string_plain(line, &pos, &head);
	}
	if (head == NULL)
		return (NULL);
	expand_str = lexer_string_lst_strjoin(head);
	ft_lstclear(&head, &free);
	return (expand_str);
}
