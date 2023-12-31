/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:31:39 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:31:39 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstmap_f(t_list *lst, void *(*f)(void *))
{
	if (lst != NULL)
	{
		if ((*f) == NULL)
			return (ft_lstnew(lst->content));
		return (ft_lstnew((*f)(lst->content)));
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*lst2_ele;

	if (lst == NULL)
		return (NULL);
	lst2 = NULL;
	while (lst != NULL)
	{
		lst2_ele = ft_lstmap_f(lst, (*f));
		if (lst2_ele == NULL)
		{
			ft_lstclear(&lst2, (*del));
			return (NULL);
		}
		ft_lstadd_back(&lst2, lst2_ele);
		lst = lst->next;
	}
	return (lst2);
}
