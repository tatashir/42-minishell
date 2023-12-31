/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmdnew_fdsize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:36:58 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:52:00 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	parser_cmdnew_fdsize(t_token *token, size_t idx, int flag)
{
	ssize_t	size;

	size = 0;
	while (token[idx].str != NULL && token[idx].flag != FLAG_PIPE)
	{
		if ((token[idx++].flag & flag) == flag)
		{
			if (token[idx++].flag != FLAG_STRING)
				return (-1);
			size++;
		}
	}
	return (size);
}
