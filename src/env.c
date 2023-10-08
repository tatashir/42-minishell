/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:23 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/08 22:21:13 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_getenv_val(char *env_key)
{
	char	*env_line;

	env_line = ms_getenv_line(env_key);
	if (env_line == NULL)
		return (NULL);
	return (ft_strchr(env_line, '=') + 1);
}
