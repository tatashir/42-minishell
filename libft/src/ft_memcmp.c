/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:32:00 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:32:00 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		dif;

	dif = 0;
	i = 0;
	while (dif == 0 && i < n)
	{
		dif = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
		i++;
	}
	return (dif);
}
