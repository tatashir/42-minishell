/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:36:14 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:03:16 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	lexer_tokenlen_delim(char *line)
{
	int		ch;
	size_t	pos;

	if (!ft_strchr(&CHRS_DELIM[1], *line))
		return (0);
	ch = *line;
	pos = 0;
	while (*(line + pos) == ch)
		pos++;
	return (pos);
}

size_t	lexer_tokenlen_quoted(char *line)
{
	int		ch;
	char	*line_end;

	if (!ft_strchr(&CHRS_QUOTE[1], *line))
		return (0);
	ch = *line;
	line_end = ft_strchr(line + 1, ch);
	if (!line_end)
		return (1);
	return (line_end - line + 1);
}

size_t	lexer_tokenlen(char *line)
{
	size_t	pos;

	pos = 0;
	if (line == NULL || *line == '\0')
		return (0);
	else if (ft_strchr(&CHRS_DELIM[1], *(line + pos)))
		return (lexer_tokenlen_delim(line + pos));
	while (*(line + pos))
	{
		if (ft_strchr(&CHRS_QUOTE[1], *(line + pos)))
			pos += lexer_tokenlen_quoted(line + pos);
		else if (ft_strchr(CHRS_DELIM, *(line + pos)))
			return (pos);
		else
			pos++;
	}
	return (pos);
}

size_t	lexer_tokenlen_plain(char *line)
{
	size_t		i;

	i = 0;
	while (line[i] && !ft_strchr(CHRS_QUOTE, line[i]))
		i++;
	return (i);
}
