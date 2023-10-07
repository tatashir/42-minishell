/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:33:59 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:33:59 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;

	if (n == 0 && (s1 == NULL || s2 == NULL))
		return (0);
	dif = 0;
	i = 0;
	while (dif == 0 && i < n && (*(s1 + i) != '\0' || *(s2 + i) != '\0'))
	{
		dif = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
		i++;
	}
	return (dif);
}
