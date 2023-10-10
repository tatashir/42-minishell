/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:28:52 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/10 18:00:51 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern t_shell	g_shell;

typedef struct sigaction	t_sa;

typedef struct s_fd {
	char	*path;
	int		fd;
}	t_fd;

typedef struct s_shell {
	t_list	*environ;
	int		status;
	t_cmd	*cmd;
	bool	kill_child;
	bool	heredoc_sigint;
}	t_shell;

typedef struct s_cmd {
	char			*path;
	char			**arg;
	t_fd			*input;
	t_fd			*output;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	pid_t			pid;
}	t_cmd;

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

int		builtin_cd(char *argv[]);
int		builtin_echo(char *argv[]);
int		builtin_env(char *argv[]);
int		builtin_exit(char *argv[]);
int		builtin_export(char *argv[]);
void	search_env_and_set(char *env_key);
int		builtin_pwd(char *argv[]);
int		builtin_unset(char *argv[]);

#endif