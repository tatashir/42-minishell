/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:33:54 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:33:55 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	len;
	size_t	i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		*(s2 + i) = (*f)(i, *(s + i));
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
