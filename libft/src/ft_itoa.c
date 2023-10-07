/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:30:52 by tatashir          #+#    #+#             */
/*   Updated: 2023/08/07 20:30:52 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_itoa_getstr(unsigned int ui, int dig)
{
	char			*str;
	unsigned int	ui_tmp;

	str = (char *)malloc((dig + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + dig) = '\0';
	if (ui == 0)
		return (ft_memset(str, '0', 1));
	while (ui > 0)
	{
		ui_tmp = ui / 10;
		dig--;
		*(str + dig) = ui - ui_tmp * 10 + '0';
		ui = ui_tmp;
	}
	if (dig > 0)
		*str = '-';
	return (str);
}

static int	ft_getdigs(unsigned int ui)
{
	int		dig;

	dig = 1;
	while (ui >= 10)
	{
		dig++;
		ui = ui / 10;
	}
	return (dig);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	ui;
	int				dig;

	if (n < 0)
		ui = -(unsigned int)(n);
	else
		ui = n;
	dig = (n < 0) + ft_getdigs(ui);
	str = ft_itoa_getstr(ui, dig);
	return (str);
}
