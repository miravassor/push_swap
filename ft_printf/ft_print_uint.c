/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:15:23 by mira              #+#    #+#             */
/*   Updated: 2022/06/07 12:39:52 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(t_print *tab)
{
	unsigned long	c;
	char			*conv;
	unsigned int	count;

	count = 0;
	c = va_arg(tab->args, unsigned int);
	if (tab->prec >= tab->width)
		tab->width = 0;
	if ((signed) c < 0 && tab->prec < 0)
	{
		tab->prec = 0;
		tab->width = 0;
	}
	if (c == 0 && tab->prec < 0 && !tab->width && !tab->zeropadd)
		return (0);
	ft_uchecker(tab, c);
	conv = ft_uitoa(c);
	if (tab->prec > 0 && tab->prec < ft_ucount(c) && c != 0)
		tab->prec = 0;
	if (tab->leftj)
		return (ft_leftalign(tab, conv, c));
	else
		return (ft_print_uend(tab, c, conv, count));
}

void	ft_uchecker(t_print *tab, unsigned long a)
{
	if (tab->zeropadd && tab->prec)
	{
		tab->zeropadd = 0;
		if (tab->prec >= tab->width)
			tab->width = 0;
	}
	if (tab->prec == -1)
	{
		if (tab->width != ft_ucount(a))
				tab->width++;
		if (tab->width == 1 && a == 0)
				tab->width++;
	}
	if (tab->prec > 0 && tab->prec < ft_ucount(a) && a != 0)
		tab->prec = 0;
}

int	ft_print_uend(t_print *tab, unsigned long c, char *conv, unsigned int count)
{
	char	*ctemp;

	ctemp = conv;
	if (tab->width)
		count += ft_print_width(tab, conv, c);
	if (tab->sp)
		count += write(1, " ", 1);
	if (tab->prec > 0)
		count += ft_print_prec(tab, c);
	if (c == 0 && tab->prec < 0)
		;
	else
	{
		while (*conv)
			count += write(1, conv++, 1);
	}
	tab->ret = 0;
	free(ctemp);
	return (count);
}
