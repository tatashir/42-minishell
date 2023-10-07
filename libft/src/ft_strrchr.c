/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:34:11 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:34:12 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_ret;

	s_ret = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			s_ret = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	if (s_ret == NULL)
		return (NULL);
	return ((char *)s_ret);
}
