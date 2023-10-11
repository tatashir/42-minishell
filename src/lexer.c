/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:36:21 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 00:02:58 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	lexer_tokensize(char *line)
{
	size_t	size;
	size_t	pos;
	size_t	len;

	if (line == NULL)
		return (0);
	size = 0;
	pos = 0;
	while (*(line + pos) != '\0')
	{
		while (*(line + pos) == CHRS_DELIM[0])
			pos++;
		len = lexer_tokenlen(line + pos);
		if (len > 0)
			size++;
		pos += len;
	}
	return (size);
}

t_token	*lexer(char *line)
{
	t_token	*token;
	size_t	size;

	size = lexer_tokensize(line);
	token = (t_token *)malloc((size + 1) * sizeof(t_token));
	if (token == NULL)
		exit(ENOMEM);
	lexer_gettoken(token, line);
	return (token);
}
