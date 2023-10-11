/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:05 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 02:44:41 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lstnew_env(char *env_key)
{
	t_list	*new;

	env_key[ft_strlen(env_key)] = '=';
	new = ft_lstnew(ft_strdup(env_key));
	if (new == NULL || new->content == NULL)
		exit(EXIT_FAILURE);
	return (new);
}

void	search_env_and_set(char *env_key)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*new;

	cur = g_shell.environ;
	prev = NULL;
	while (cur != NULL)
	{
		if (is_same_envkey(cur->content, env_key))
		{
			free(cur->content);
			env_key[ft_strlen(env_key)] = '=';
			cur->content = ft_strdup(env_key);
			if (cur->content == NULL)
				exit(EXIT_FAILURE);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	new = lstnew_env(env_key);
	if (prev == NULL)
		g_shell.environ = new;
	else
		prev->next = new;
}

int	set_environ(char **argv)
{
	int		return_status;
	size_t	i;
	char	*eq;

	return_status = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		eq = ft_strchr(argv[i], '=');
		if (eq == NULL)
		{
			i++;
			continue ;
		}
		*eq = '\0';
		if (is_validenv(argv[i]) == false)
		{
			*eq = '=';
			printf(MSG_INVAL_ID, "export", argv[i++]);
			return_status = 1;
		}
		else
			search_env_and_set(argv[i++]);
	}
	return (return_status);
}

static int	print_env_with_declare(void)
{
	t_list	*cur;
	char	*eq;

	cur = g_shell.environ;
	while (cur != NULL)
	{
		ft_putstr_fd(MSG_DECLARE, STDOUT_FILENO);
		eq = ft_strchr(cur->content, '=');
		write(STDOUT_FILENO, cur->content, eq - (char *)cur->content + 1);
		ft_putstr_fd(STR_QUOTE, STDOUT_FILENO);
		ft_putstr_fd(eq + 1, STDOUT_FILENO);
		ft_putendl_fd(STR_QUOTE, STDOUT_FILENO);
		cur = cur->next;
	}
	return (0);
}

int	builtin_export(char *argv[])
{
	int	return_status;

	if (argv[1] == NULL)
		return (print_env_with_declare());
	return_status = set_environ(&argv[1]);
	return (return_status);
}
