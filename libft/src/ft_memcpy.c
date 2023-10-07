/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:32:06 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:32:06 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_end;

	if (dst == NULL || src == NULL || n == 0)
		return (dst);
	dst_end = dst + --n;
	while (dst <= dst_end)
		*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	return (dst_end - n);
}
