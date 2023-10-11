/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:34:46 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 05:16:27 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(char *argv[])
{
	bool		print_nl;
	size_t		start;
	size_t		i;

	if (argv[0] == NULL)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (1);
	}
	print_nl = !(argv[1] && ft_strcmp(argv[1], "-n") == 0);
	start = 2 - print_nl;
	i = start;
	while (argv[i] != NULL)
	{
		if (i > start)
			ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putstr_fd(argv[i++], STDOUT_FILENO);
	}
	if (print_nl)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
