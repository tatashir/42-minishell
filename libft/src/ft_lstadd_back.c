/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:30:57 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:30:58 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev;

	if (lst == NULL)
		lst = &new;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		prev = ft_lstlast(*lst);
		prev->next = new;
	}
}
