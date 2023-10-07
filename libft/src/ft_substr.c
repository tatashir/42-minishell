/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:34:22 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:34:22 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*s2;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (start + len > len_s)
		len = len_s - start;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}
