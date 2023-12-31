/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:37:38 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:54:04 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	strisdigit(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
