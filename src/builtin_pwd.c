/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:35:11 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/09 19:53:44 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(char *argv[])
{
	char	cwd[PATH_MAX + 1];
	char	*pwd;

	if (argv == NULL)
		return (0);
	errno = 0;
	getcwd(cwd, PATH_MAX);
	pwd = getenv_val("PWD");
	if (pwd != NULL && ft_strcmp(cwd, pwd + 1) == 0)
		ft_strlcpy(cwd, pwd, PATH_MAX + 1);
	ft_putendl_fd(cwd, STDOUT_FILENO);
	return (errno);
}
