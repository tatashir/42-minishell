/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmdnew_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:36:54 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:51:43 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	parser_cmdnew_arg_size(t_token *token, size_t idx)
{
	size_t	size;

	size = 0;
	while (token[idx].str != NULL && token[idx].flag != FLAG_PIPE)
	{
		if (token[idx].flag == FLAG_STRING)
			size++;
		else
			idx++;
		if (token[idx].str != NULL && token[idx].flag != FLAG_PIPE)
			idx++;
	}
	return (size);
}

char	**parser_cmdnew_arg(t_token *token, size_t i_token)
{
	char	**arg;
	size_t	size;
	size_t	i_arg;

	size = parser_cmdnew_arg_size(token, i_token);
	arg = (char **)malloc((size + 1) * sizeof(char *));
	if (arg == NULL)
		return (NULL);
	i_arg = 0;
	while (token[i_token].str != NULL && token[i_token].flag != FLAG_PIPE)
	{
		if (token[i_token].flag == FLAG_STRING)
			arg[i_arg++] = token[i_token].str;
		else
			i_token++;
		if (token[i_token].str != NULL && token[i_token].flag != FLAG_PIPE)
			i_token++;
	}
	arg[size] = NULL;
	return (arg);
}
