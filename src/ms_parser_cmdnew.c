/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_cmdnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:37:13 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:37:13 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ms_parser_cmdnew(t_token *token, size_t *idx)
{
	t_cmd	*cmd;

	if (token == NULL || token[*idx].str == NULL)
		return (NULL);
	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->input = ms_parser_cmdnew_input(token, *idx);
	if (cmd->input == NULL)
		return (ms_clear_cmd_and_return_null(cmd));
	cmd->output = ms_parser_cmdnew_output(token, *idx);
	if (cmd->output == NULL)
		return (ms_clear_cmd_and_return_null(cmd));
	cmd->arg = ms_parser_cmdnew_arg(token, *idx);
	if (cmd->arg == NULL)
		return (ms_clear_cmd_and_return_null(cmd));
	cmd->path = ms_getpath_cmd(cmd->arg[0]);
	if (cmd->path == NULL)
		return (ms_clear_cmd_and_return_null(cmd));
	while (token[*idx].str != NULL && token[*idx].flag != FLAG_PIPE)
		(*idx)++;
	return (cmd);
}
