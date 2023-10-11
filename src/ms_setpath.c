/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:37:23 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 00:30:07 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setpath_home(char *path, char *arg)
{
	ft_strlcpy(path, getenv_val(ENV_HOME), PATH_MAX + 1);
	ft_strlcat(path, &arg[1], PATH_MAX + 1);
}

void	setpath_absolute(char *path, char *arg)
{
	ft_strlcpy(path, arg, PATH_MAX + 1);
}

void	setpath_relative(char *path, char *arg)
{
	char	*pwd;
	char	cwd[PATH_MAX + 1];

	pwd = getenv_val("PWD");
	if (pwd == NULL)
		ft_strlcpy(path, getcwd(cwd, PATH_MAX), PATH_MAX + 1);
	else
		ft_strlcpy(path, pwd, PATH_MAX + 1);
	if (path[1] != '\0' && path[1] != '/')
		ft_strlcat(path, STR_DIR, PATH_MAX + 1);
	ft_strlcat(path, arg, PATH_MAX + 1);
}
