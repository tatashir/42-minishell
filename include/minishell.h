/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:28:52 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 05:17:13 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

typedef struct s_token {
	char	*str;
	int		flag;
}	t_token;

typedef struct s_fd {
	char	*path;
	int		fd;
}	t_fd;

typedef struct s_cmd {
	char			*path;
	char			**arg;
	t_fd			*input;
	t_fd			*output;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	pid_t			pid;
}	t_cmd;

typedef struct s_shell {
	t_list	*environ;
	int		status;
	t_cmd	*cmd;
	bool	kill_child;
	bool	heredoc_sigint;
}	t_shell;

extern t_shell				g_shell;
typedef struct sigaction	t_sa;

void	init_global(char *envp[]);
void	sigset_rl(void);
void	sigset_rl_heredoc(void);
void	sigset_exec(void);
void	sigset_noquit(void);
void	sighandler_rl(int signum, siginfo_t *info, void *context);
void	sighandler_rl_heredoc(int signum, siginfo_t *info, void *context);
void	sighandler_exec(int signum, siginfo_t *info, void *context);

t_token	*lexer(char *line);

void	lexer_gettoken(t_token *token, char *line);

size_t	lexer_tokenlen(char *line);
size_t	lexer_tokenlen_quoted(char *line);
size_t	lexer_tokenlen_plain(char *line);

char	*lexer_string(char *line);

t_cmd	*parser(t_token *token);
t_cmd	*parser_cmdnew(t_token *token, size_t *idx);
char	**parser_cmdnew_arg(t_token *token, size_t i_token);
size_t	parser_cmdnew_fdsize(t_token *token, size_t idx, int flag);
t_fd	*parser_cmdnew_input(t_token *token, size_t i_token);
t_fd	*parser_cmdnew_output(t_token *token, size_t i_token);

bool	isenvchar(int c);
char	*search_env(char *env_key);
t_list	*expand_envvar(char *line, size_t *pos, size_t len);
t_list	*expand_envvar_dquote(char *line, size_t len);
char	*getenv_line(char *env_key);
char	*getenv_val(char *env_key);
bool	is_same_envkey(char *dest, char *src);
bool	is_validenv(char *env_candidate);

void	lexer_string_lstadd_back_substr(t_list **head, char *line, \
			size_t pos, size_t len);
char	*lexer_string_lst_strjoin(t_list *head);

char	*getpath_cmd(char *name);
char	*getpath_relative(char *name);
char	*getpath_envpath(char *name);
char	*getpath_join(char *dirpath, char *name);
void	setpath_home(char *path, char *arg);
void	setpath_absolute(char *path, char *arg);
void	setpath_relative(char *path, char *arg);

void	exec_cmd(t_cmd *cmd);
void	exec_in_child_process(t_cmd *cmd);
void	exec_a_builtin(t_cmd *cmd, int (*builtin)(char *arg[]));

void	fd_close(int fd[2]);
void	fd_copy(int dest[2], int src[2]);
int		fd_last_fd(t_fd *fd_lst);
void	fd_close_all_cmd(t_cmd *cmd);
void	init_fd(int fd[2]);

int		(*builtin_getfunc(char *arg))(char *argv[]);
int		builtin_cd(char *argv[]);
int		builtin_echo(char *argv[]);
int		builtin_env(char *argv[]);
int		builtin_exit(char *argv[]);
int		builtin_export(char *argv[]);
void	search_env_and_set(char *env_key);
int		builtin_pwd(char *argv[]);
int		builtin_unset(char *argv[]);

size_t	strlst_count(char *str_lst[]);
void	strlst_cpy(char **dest, char **src);
void	strlst_free(char *argv[]);
void	*lstclear_return_null(t_list **head);
char	**map_lst2map(t_list *lst);
void	*map_clear(char **map, size_t size);
size_t	map_size(char **map);

bool	strisdigit(char *str);
void	*free_and_return(void *malloc_obj);
void	*print_err_set_status_return_null(char *str, int status);
void	*clear_cmd_and_return_null(t_cmd *head);
bool	is_directory(char *path);

# define CHRS_DELIM			" <>|"
# define CHRS_QUOTE			"$\"'"

# define STR_EMPTY			""
# define STR_DIR			"/"
# define STR_OLDPWD			"-"
# define STR_QUOTE			"'"
# define STR_DQUOTE			"\""
# define STR_EXPAND			"$"

# define ENV_HOME			"HOME"
# define ENV_PATH			"PATH"
# define ENV_PWD			"PWD"
# define ENV_OLDPWD			"OLDPWD"

# define MSG_SIG_QUIT		"Quit: 3"
# define MSG_SYNTAX_ERR		"syntax error"
# define MSG_EXIT			"exit"
# define MSG_NO_HOME		"HOME not set"
# define MSG_NO_OLDPWD		"OLDPWD not set"
# define MSG_ENOENT			"No such file or directory"
# define MSG_ARG_NOTNUM		"numeric argument required"
# define MSG_ARG_MANY		"too many arguments"
# define MSG_DECLARE		"declare -x "
# define MSG_INVAL_ID		"bash: %s: `%s\" : not a valid identifier\n"
# define MSG_NO_CMD			"command not found"
# define MSG_ISDIR			"Is a directory"

# define PROMPT_MINISH		"minishell $ "
# define PROMPT_HREDOC		"> "

//# define FLAG_NONE			0x00
# define FLAG_STRING		0x10
# define FLAG_IN			0x20
# define FLAG_HEREDOC		0x22
# define FLAG_OUT			0x40
# define FLAG_APPEND		0x44
# define FLAG_PIPE			0x80
# define SHIFT_FLAG			4

# define LEN_QUOTE_CLOSED	2
# define LEN_QUOTE_UNCLOSED	1

// int		builtin_cd(char *argv[]);
// int		builtin_echo(char *argv[]);
// int		builtin_env(char *argv[]);
// int		builtin_exit(char *argv[]);
// int		builtin_export(char *argv[]);
// void	search_env_and_set(char *env_key);
// int		builtin_pwd(char *argv[]);
// int		builtin_unset(char *argv[]);

#endif