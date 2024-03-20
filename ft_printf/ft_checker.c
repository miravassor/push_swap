/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:30:00 by avassor           #+#    #+#             */
/*   Updated: 2022/10/13 15:11:14 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ret1(t_print *tab)
{
	int	len;
	int	padd;

	len = 0;
	padd = 0;
	if (tab->leftj)
		len += write(1, "(null)", 6);
	padd = tab->width - 6;
	while (padd-- > 0)
		len += write(1, " ", 1);
	if (!tab->leftj)
		len += write(1, "(null)", 6);
	tab->ret++;
	return (len);
}

int	ft_check_sign(t_print *tab, long c)
{
	int	count;

	count = 0;
	if (tab->sign || c < 0)
	{
		if (c >= 0)
			count += write(1, "+", 1);
		else if (c < 0)
		{
			tab->sign = 1;
			count += write(1, "-", 1);
		}
	}
	return (count);
}

int	ft_check_prec(t_print *tab, long c)
{
	int	nprec;

	nprec = 0;
	if (tab->prec > 0)
	{
		if (tab->prec >= ft_count(c))
			nprec += tab->prec - ft_count(c);
		else
			nprec += tab->width - ft_count(c);
	}
	return (nprec);
}

int	ft_check_szero(t_print *tab)
{
	int	count;

	count = write(1, "-", 1);
	tab->sign = 0;
	tab->ret = 1;
	return (count);
}

int	ft_check_intflg(t_print *tab, long c)
{
	if (!c && c != 0)
		return (1);
	if (c == 0 && tab->prec < 0 && !tab->width && !tab->zeropadd)
		return (1);
	if (tab->zeropadd && tab->prec)
	{
		tab->zeropadd = 0;
		if (tab->prec >= tab->width)
			tab->width = 0;
	}
	if (tab->prec == -1)
	{
		if (tab->width != ft_count(c))
				tab->width++;
		if (tab->width == 1 && c == 0)
				tab->width++;
	}
	if (tab->prec > 0 && tab->prec < ft_count(c) && c != 0)
		tab->prec = 0;
	if (c < 0)
		tab->neg = 1;
	return (0);
}
