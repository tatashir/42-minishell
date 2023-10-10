/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_gettoken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:57 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/10 21:12:52 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexer_gettoken_classify(char *line)
{
	int	flag;

	if (line == NULL)
		return (0x00);
	if (!ft_strchr(CHRS_DELIM, *line))
		return (FLAG_STRING);
	flag = 0x00;
	if (*line == '<')
		flag = FLAG_IN;
	else if (*line == '>')
		flag = FLAG_OUT;
	else if (*line == '|')
		flag = FLAG_PIPE;
	else if (*line == '|')
		flag = FLAG_PIPE;
	if (*(line + 1) == '\0')
		return (flag);
	else if (*line == *(line + 1))
		flag += flag >> SHIFT_FLAG;
	if (*(line + 2) == '\0' && *(line + 1) != '|')
		return (flag);
	return (0x00);
}

void	lexer_gettoken(t_token *token, char *line)
{
	char	*str;
	size_t	pos;
	size_t	len;
	size_t	i;

	pos = 0;
	i = 0;
	while (*(line + pos) != '\0')
	{
		while (*(line + pos) == ' ')
			pos++;
		len = lexer_tokenlen(line + pos);
		str = ft_substr(line, pos, len);
		if (str == NULL)
			exit(ENOMEM);
		token[i].flag = lexer_gettoken_classify(str);
		token[i].str = lexer_string(str);
		free(str);
		pos += len;
		if (token[i].str != NULL)
			i++;
	}
	token[i].str = NULL;
	return ;
}
