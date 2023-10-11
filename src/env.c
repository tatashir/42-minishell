/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:23 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/11 22:58:47 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_validenv(char *env_candidate)
{
	if (!(ft_isalpha(*env_candidate) || *env_candidate == '_'))
		return (false);
	env_candidate++;
	while (*env_candidate)
	{
		if (!isenvchar(*env_candidate))
			return (false);
		env_candidate++;
	}
	return (true);
}

bool	is_same_envkey(char *dest, char *src)
{
	return (ft_strncmp(dest, src, ft_strlen(src)) == 0 \
			&& dest[ft_strlen(src)] == '=');
}

char	*getenv_val(char *env_key)
{
	char	*env_line;

	env_line = getenv_line(env_key);
	if (env_line == NULL)
		return (NULL);
	return (ft_strchr(env_line, '=') + 1);
}

char	*getenv_line(char *env_key)
{
	t_list	*cur;

	cur = g_shell.environ;
	while (cur != NULL)
	{
		if (is_same_envkey(cur->content, env_key))
			return (cur->content);
		cur = cur->next;
	}
	return (NULL);
}
