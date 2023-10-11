/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmdnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:37:13 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:52:53 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parser_cmdnew(t_token *token, size_t *idx)
{
	t_cmd	*cmd;

	if (token == NULL || token[*idx].str == NULL)
		return (NULL);
	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->input = parser_cmdnew_input(token, *idx);
	if (cmd->input == NULL)
		return (clear_cmd_and_return_null(cmd));
	cmd->output = parser_cmdnew_output(token, *idx);
	if (cmd->output == NULL)
		return (clear_cmd_and_return_null(cmd));
	cmd->arg = parser_cmdnew_arg(token, *idx);
	if (cmd->arg == NULL)
		return (clear_cmd_and_return_null(cmd));
	cmd->path = getpath_cmd(cmd->arg[0]);
	if (cmd->path == NULL)
		return (clear_cmd_and_return_null(cmd));
	while (token[*idx].str != NULL && token[*idx].flag != FLAG_PIPE)
		(*idx)++;
	return (cmd);
}
