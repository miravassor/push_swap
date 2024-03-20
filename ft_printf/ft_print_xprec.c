/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xprec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:25:51 by avassor           #+#    #+#             */
/*   Updated: 2022/06/02 17:20:07 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xend(t_print *tab, const char *pform, unsigned long long i,
					int count)
{
	if (tab->width)
		count += ft_xprint_width(tab, i, pform);
	if (tab->prec)
		count += ft_print_xprec(tab, i);
	else if (tab->hash && i != 0)
		count += ft_print_hash(pform);
	if (i == 0 && tab->prec < 0)
		;
	else
		count += ft_put_x(tab, i, pform);
	return (count);
}

void	ft_xcheck(t_print *tab, unsigned long long i)
{
	if (tab->zeropadd && tab->prec)
	{
		tab->zeropadd = 0;
		if (tab->prec >= tab->width)
			tab->width = 0;
	}
	if (tab->prec == -1)
	{
		if (tab->width != ft_xcount(i))
				tab->width++;
		if (tab->width == 1 && i == 0)
				tab->width++;
	}
}

int	ft_put_xlen(unsigned long long i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	while (i)
	{
		count++;
		i /= 16;
	}
	return (count);
}

int	ft_xleft_align(t_print *tab, unsigned long long i, const char *pform)
{
	int		count;
	int		nprec;

	count = 0;
	nprec = 0;
	if (tab->prec > 0)
	{
		if (tab->prec >= ft_xcount(i))
			nprec += tab->prec - ft_xcount(i);
		else
			nprec += tab->width - ft_xcount(i);
	}
	while (nprec-- > 0)
		count += write(1, "0", 1);
	if (i == 0 && tab->prec < 0)
		;
	else
		count += ft_put_x(tab, i, pform);
	if (tab->hash)
		count += ft_print_hash(pform);
	if (tab->width)
		count += ft_xprint_width(tab, i, pform);
	return (count);
}
