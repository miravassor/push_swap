/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:48:27 by mira              #+#    #+#             */
/*   Updated: 2022/06/07 17:01:09 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlj(t_print *tab, const char *c, int count, int len)
{
	if (tab->width)
	{
		if (tab->prec && tab->prec < ft_strprec(tab, c))
			tab->ttlen = tab->width - tab->prec;
		else
			tab->ttlen = tab->width - len;
	}
	if (tab->prec)
	{
		while (*c && tab->prec--)
			count += write(1, c++, 1);
	}
	else
		while (*c)
			count += write(1, c++, 1);
	if (tab->width)
	{
		while (tab->ttlen-- > 0)
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_strend(t_print *tab, const char *c, int count, int len)
{
	if (tab->width)
	{
		if (tab->prec)
			tab->ttlen = tab->width - tab->prec;
		else
			tab->ttlen = tab->width - len;
		while (tab->ttlen-- > 0)
			count += write(1, " ", 1);
	}
	if (tab->prec)
	{
		while (*c && tab->prec--)
			count += write(1, c++, 1);
		return (count);
	}
	else
		while (*c)
			count += write(1, c++, 1);
	return (count);
}
