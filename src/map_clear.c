/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:36:38 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:36:38 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*map_clear(char **map, size_t size)
{
	size_t	i;

	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
	map = NULL;
	return (NULL);
}
