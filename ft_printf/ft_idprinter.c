/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idprinter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:44:30 by avassor           #+#    #+#             */
/*   Updated: 2022/06/07 12:49:15 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_printer(t_print *tab, char *conv, long c)
{
	int	count;

	count = 0;
	if (c == 0 && tab->prec < 0)
		return (0);
	else
	{
		while (*conv)
			count += write(1, conv++, 1);
	}
	return (count);
}

int	ft_iswidth(t_print *tab, const char *pform)
{
	int	wdth;
	int	count;

	wdth = 0;
	count = 0;
	while (*pform >= '0' && *pform <= '9')
	{
		wdth *= 10;
		wdth += *pform - 48;
		tab->narg += 1;
		tab->width = wdth;
		count++;
		pform++;
	}
	return (count);
}

int	ft_isprec(t_print *tab, const char *pform)
{
	int	count;

	count = 0;
	tab->narg += 1;
	tab->point = 1;
	++pform;
	++count;
	if (!(*pform >= '1' && *pform <= '9'))
	{
		if (*pform == '0')
		{
			count++;
			pform++;
			tab->narg += 1;
		}
		tab->prec = -1;
	}
	if (*pform >= '0' && *pform <= '9')
		count += ft_print_pre(tab, pform);
	return (count);
}

int	ft_print_pre(t_print *tab, const char *pform)
{
	int	count;
	int	wdth;

	count = 0;
	wdth = 0;
	while (*pform >= '0' && *pform <= '9')
	{
		wdth *= 10;
		wdth += *pform - 48;
		tab->narg += 1;
		tab->prec = wdth;
		pform++;
		count++;
	}
	return (count);
}
