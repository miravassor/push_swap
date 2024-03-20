/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:11:30 by avassor           #+#    #+#             */
/*   Updated: 2022/06/07 16:59:53 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++i;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_xcount(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++i;
		n *= -1;
	}
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	ft_sepid(t_print *tab)
{
	if (tab->zeropadd && !tab->prec)
		return ('0');
	else
		return (' ');
}

int	ft_print_xprec(t_print *tab, unsigned long long c)
{
	int		wdth;
	int		count;
	char	sep;

	wdth = tab->prec - ft_xcount(c);
	sep = '0';
	count = 0;
	while (wdth-- > 0)
		count += write(1, &sep, 1);
	return (count);
}

int	ft_checkerror(t_print *tab, const char *pform)
{
	if (tab->sp && tab->sign)
		return (1);
	if ((tab->hash && *pform != 'x') && (tab->hash && *pform != 'X'))
		return (1);
	if ((tab->zeropadd && *pform != 'd') && (tab->zeropadd && *pform != 'i')
		&& (tab->zeropadd && *pform != 'u') && (tab->zeropadd && *pform != 'x')
		&& (tab->zeropadd && *pform != 'X'))
		return (1);
	if ((tab->sp && *pform != 'd') && (tab->sp && *pform != 'i')
		&& (tab->sp && *pform != 's'))
		return (1);
	if ((tab->sign && *pform != 'd') && (tab->sign && *pform != 'i'))
		return (1);
	return (0);
}
