/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:00:15 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 01:24:31 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cmd_readline(void)
{
	char	*line;

	sigset_rl();
	sigset_noquit();
	rl_done = 0;
	rl_event_hook = NULL;
	line = readline(PROMPT_MINISH);
	if (line == NULL)
		return (NULL);
	return (line);
}

static void	clear_token(t_token *token)
{
	size_t	i;

	if (token == NULL)
		return ;
	i = 0;
	while (&token[i] && token[i].str)
	{
		free(token[i].str);
		i++;
	}
	free(token);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_token	*token;

	(void)argc;
	(void)argv;
	init_global(envp);
	while (1)
	{
		line = cmd_readline();
		if (line == NULL)
			break ;
		if (*line)
		{
			add_history(line);
			token = lexer(line);
			g_shell.cmd = parser(token);
			sigset_exec();
			exec_cmd(g_shell.cmd);
			clear_token(token);
		}
		free(line);
	}
	builtin_exit(NULL);
	return (g_shell.status);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q minishell");
// }
