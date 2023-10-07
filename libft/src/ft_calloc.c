/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:29:58 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:29:59 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	prod;

	if (count == 0 || size == 0)
		prod = 1;
	else
	{
		prod = size * count;
		if (prod / size < count)
			prod = (size_t)(-1);
	}
	ptr = malloc(prod);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, prod);
	return (ptr);
}
