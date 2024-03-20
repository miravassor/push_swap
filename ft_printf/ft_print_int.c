/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:59:56 by avassor           #+#    #+#             */
/*   Updated: 2022/09/21 16:22:31 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(t_print *tab)
{
	long		c;
	char		*conv;
	int			count;

	count = 0;
	c = va_arg(tab->args, int);
	if (tab->prec >= tab->width)
		tab->width = 0;
	if (tab->zeropadd && tab->leftj)
		tab->zeropadd = 0;
	if (ft_check_intflg(tab, c))
		return (0);
	if (tab->zeropadd && tab->neg)
	{
		count += ft_check_szero(tab);
		c *= -1;
	}
	conv = ft_itoa(c);
	if (tab->leftj)
		return (ft_leftalign(tab, conv, c));
	if (tab->width)
		count += ft_print_width(tab, conv, c);
	return (ft_print_int_end(tab, count, conv, c));
}

int	ft_print_int_end(t_print *tab, int count, char *conv, long c)
{
	int		fcount;
	char	*ctemp;

	fcount = count;
	fcount += ft_check_sign(tab, c);
	ctemp = conv;
	if (tab->sign == 1 && c < 0)
	{
		++conv;
		c *= -1;
	}
	if (tab->sp && !tab->sign)
		fcount += write(1, " ", 1);
	if (tab->prec > 0)
		fcount += ft_print_prec(tab, c);
	if (c == 0 && tab->prec < 0)
		;
	else
	{
		while (*conv)
			fcount += write(1, conv++, 1);
	}
	tab->ret = 0;
	free(ctemp);
	return (fcount);
}

int	ft_print_prec(t_print *tab, long c)
{
	int		wdth;
	int		count;
	char	sep;

	wdth = tab->prec - ft_count(c);
	sep = '0';
	count = 0;
	while (wdth-- > 0)
		count += write(1, &sep, 1);
	return (count);
}
