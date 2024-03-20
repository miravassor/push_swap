/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:12:55 by avassor           #+#    #+#             */
/*   Updated: 2022/06/07 12:41:47 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cleft_align(t_print *tab, char c)
{
	int	count;
	int	padd;

	count = 0;
	count += write(1, &c, 1);
	padd = tab->width - count;
	while (padd-- > 0)
		count += write(1, " ", 1);
	return (count);
}

int	ft_print_char(t_print *tab)
{
	int		c;
	int		count;
	int		padd;

	count = 0;
	c = va_arg(tab->args, int);
	if (tab->leftj)
		return (ft_cleft_align(tab, c));
	if (tab->width)
	{
		padd = tab->width - 1;
		while (padd-- > 0)
			count += write(1, " ", 1);
	}
	count += write(1, &c, 1);
	return (count);
}
