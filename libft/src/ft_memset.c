/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:32:15 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:32:16 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	void	*buf_end;

	if (n == 0)
		return (buf);
	buf_end = buf + --n;
	while (buf <= buf_end)
		*(unsigned char *)(buf++) = (unsigned char)ch;
	return (buf_end - n);
}
