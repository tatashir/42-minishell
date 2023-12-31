/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:49 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 02:48:29 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getpath_join(char *dirpath, char *name)
{
	char	*path;
	size_t	len_dir;
	size_t	len_name;

	len_dir = ft_strlen(dirpath);
	len_name = ft_strlen(name);
	path = (char *)malloc((len_dir + len_name + 2) * sizeof(char));
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, dirpath, len_dir + 1);
	*(path + len_dir) = '/';
	ft_strlcpy(path + len_dir + 1, name, len_name + 1);
	return (path);
}

char	*getpath_relative(char *name)
{
	char	*path;
	char	*pwd;
	char	cwd[PATH_MAX + 1];

	pwd = getenv_val("PWD");
	if (pwd == NULL)
		path = getpath_join(getcwd(cwd, PATH_MAX), name);
	else
		path = getpath_join(pwd, name);
	return (path);
}

char	*getpath_envpath_iter(char *name, char **envpath_split)
{
	char		*cmdpath;
	struct stat	stat_buf;
	size_t		i;

	if (envpath_split == NULL)
		return (NULL);
	i = 0;
	while (envpath_split[i])
	{
		cmdpath = getpath_join(envpath_split[i], name);
		if (cmdpath == NULL)
			return (map_clear(envpath_split, map_size(envpath_split)));
		stat(cmdpath, &stat_buf);
		if ((stat_buf.st_mode & S_IFMT) == S_IFREG)
			return (cmdpath);
		cmdpath = free_and_return(cmdpath);
		i++;
	}
	return (NULL);
}

char	*getpath_envpath(char *name)
{
	char		*cmdpath;
	char		*envpath;
	char		**envpath_split;

	envpath = getenv_val(ENV_PATH);
	if (envpath == NULL)
		return (ft_strdup(name));
	envpath_split = ft_split(envpath, ':');
	if (envpath_split == NULL)
		return (NULL);
	cmdpath = getpath_envpath_iter(name, envpath_split);
	envpath_split = map_clear(envpath_split, map_size(envpath_split));
	if (!cmdpath)
		cmdpath = ft_strdup(STR_EMPTY);
	return (cmdpath);
}

char	*getpath_cmd(char *name)
{
	if (name == NULL)
		return (NULL);
	if (builtin_getfunc(name))
		return (ft_strdup(name));
	else if (*name == '/')
		return (ft_strdup(name));
	else if (ft_strchr(name, '/'))
		return (getpath_relative(name));
	return (getpath_envpath(name));
}
