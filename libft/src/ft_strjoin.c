/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:33:34 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:33:34 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcpy(s3 + len_s1, s2, len_s2 + 1);
	return (s3);
}
