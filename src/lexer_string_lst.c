/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_string_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:36:05 by tatashir          #+#    #+#             */
/*   Updated: 2023/10/12 03:02:45 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_string_lstadd_back_substr(t_list **head, char *line, \
	size_t pos, size_t len)
{
	char	*substr;

	substr = ft_substr(line, pos, len);
	if (substr == NULL)
		exit(EXIT_FAILURE);
	ft_lstadd_back(head, ft_lstnew(substr));
	return ;
}

char	*lexer_string_lst_strjoin(t_list *head)
{
	size_t	joined_str_size;
	char	*joined_str;
	t_list	*cur;

	joined_str_size = 0;
	cur = head;
	while (cur != NULL)
	{
		if (cur->content != NULL)
			joined_str_size += ft_strlen(cur->content);
		cur = cur->next;
	}
	joined_str = ft_calloc(joined_str_size + 1, sizeof(char));
	if (joined_str == NULL)
		exit(EXIT_FAILURE);
	cur = head;
	while (cur != NULL)
	{
		if (cur->content != NULL)
			ft_strlcat(joined_str, cur->content, joined_str_size + 1);
		cur = cur->next;
	}
	return (joined_str);
}
