/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:31:29 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:31:29 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if ((*f) != NULL)
	{
		while (lst != NULL)
		{
			if (lst->content != NULL)
				(*f)(lst->content);
			lst = lst->next;
		}
	}
}
