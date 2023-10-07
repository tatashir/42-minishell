/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:31:17 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:31:17 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	void	*next;
	t_list	*ele;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		ele = *lst;
		next = ele->next;
		ft_lstdelone(*lst, (*del));
		*lst = next;
	}
	lst = NULL;
}
