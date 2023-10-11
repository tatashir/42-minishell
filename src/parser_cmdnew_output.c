/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmdnew_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:37:08 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 00:26:02 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	parser_output_sub(t_fd *output, t_token *token, size_t *i_token)
{
	ssize_t	i_output;

	i_output = 0;
	while (token[*i_token].str != NULL && token[*i_token].flag != FLAG_PIPE)
	{
		if ((token[*i_token].flag & FLAG_OUT) == FLAG_OUT)
		{
			if (token[*i_token].flag == FLAG_APPEND)
				output[i_output].fd = open(token[++(*i_token)].str, \
										O_WRONLY | O_CREAT | O_APPEND, 0666);
			else
				output[i_output].fd = open(token[++(*i_token)].str, \
										O_WRONLY | O_CREAT | O_TRUNC, 0666);
			if (output[i_output].fd < 0)
				return (false);
			output[i_output++].path = token[*i_token].str;
		}
		(*i_token)++;
	}
	output[i_output].path = NULL;
	output[i_output].fd = -1;
	return (true);
}

t_fd	*parser_cmdnew_output(t_token *token, size_t i_token)
{
	t_fd	*output;
	ssize_t	size;

	size = parser_cmdnew_fdsize(token, i_token, FLAG_OUT);
	if (size == -1)
		return (print_err_set_status_return_null(\
				MSG_SYNTAX_ERR, 258));
	output = (t_fd *)malloc((size + 1) * sizeof(t_fd));
	if (output == NULL)
		exit(EXIT_FAILURE);
	if (parser_output_sub(output, token, &i_token) == false)
	{
		free(output);
		return (print_err_set_status_return_null(\
				strerror(errno), 1));
	}
	return (output);
}
