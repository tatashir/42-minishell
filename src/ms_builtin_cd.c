/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:34:37 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/11 22:40:48 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_builtin_cd_export(char *key, char *val)
{
	char	*keyval;
	size_t	len;

	if (key == NULL || val == NULL)
		return (1);
	len = ft_strlen(key) + 1;
	keyval = (char *)malloc((len + ft_strlen(val) + 1) * sizeof(char));
	if (keyval == NULL)
		return (errno);
	ft_strlcpy(keyval, key, len);
	ft_strlcpy(keyval + len, val, ft_strlen(val) + 1);
	ms_search_env_and_set(keyval);
	free(keyval);
	return (0);
}

static int	ms_builtin_cd_chdir(char *path)
{
	if (path == NULL || chdir(path))
	{
		ft_putendl_fd(MSG_ENOENT, STDERR_FILENO);
		return (1);
	}
	ms_builtin_cd_export(ENV_OLDPWD, ms_getenv_val("PWD"));
	if (path[0] == '/' && path[1] == '/' && path[2] != '/')
		getcwd(path + 1, PATH_MAX - 1);
	else
		getcwd(path, PATH_MAX);
	ms_builtin_cd_export("PWD", path);
	return (0);
}

static int	ms_builtin_cd_env(char	*key)
{
	char	*val;

	val = ms_getenv_val(key);
	if (val)
		return (ms_builtin_cd_chdir(val));
	else if (ft_strcmp(key, ENV_HOME) == 0)
		ft_putendl_fd(MSG_NO_HOME, STDERR_FILENO);
	else if (ft_strcmp(key, ENV_OLDPWD) == 0)
		ft_putendl_fd(MSG_NO_OLDPWD, STDERR_FILENO);
	else
		return (ms_builtin_cd_chdir(NULL));
	return (1);
}

int	ms_builtin_cd(char	*argv[])
{
	char	path[PATH_MAX + 1];
	int		status;

	if (argv == NULL || argv[1] == NULL)
		return (ms_builtin_cd_env(ENV_HOME));
	else if (argv[1][0] == '~' \
		&& (argv[1][1] == '/' || argv[1][1] == '\0'))
	{
		if (ms_getenv_val(ENV_HOME) == NULL)
			return (ms_builtin_cd_env(ENV_HOME));
		ms_setpath_home(path, argv[1]);
	}
	else if (ft_strcmp(argv[1], STR_OLDPWD) == 0)
		return (ms_builtin_cd_env(ENV_OLDPWD));
	else if (argv[1][0] == '/')
		ms_setpath_absolute(path, argv[1]);
	else
		ms_setpath_relative(path, argv[1]);
	status = ms_builtin_cd_chdir(path);
	return (status);
}
