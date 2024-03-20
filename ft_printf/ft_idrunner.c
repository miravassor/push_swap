/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idrunner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:21:50 by avassor           #+#    #+#             */
/*   Updated: 2022/06/02 16:26:47 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ishash(t_print *tab, const char *pform)
{
	(void) pform;
	tab->hash = 2;
	tab->narg += 1;
	return (1);
}

int	ft_isdash(t_print *tab, const char *pform)
{
	int	count;

	count = 0;
	while (*pform == '-')
	{
		tab->narg += 1;
		count++;
		pform++;
	}
	tab->leftj = 1;
	return (count);
}

int	ft_isplus(t_print *tab, const char *pform)
{
	(void) pform;
	tab->sign = 1;
	tab->narg += 1;
	return (1);
}

int	ft_isspace(t_print *tab, const char *pform)
{
	(void) pform;
	tab->sp = 1;
	tab->narg += 1;
	return (1);
}

int	ft_iszero(t_print *tab, const char *pform)
{
	int	count;

	count = 0;
	while (*pform == '0')
	{
		tab->narg += 1;
		++count;
		++pform;
	}
	tab->zeropadd = 1;
	return (count);
}
