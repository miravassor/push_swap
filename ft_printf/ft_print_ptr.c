/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:02:24 by mira              #+#    #+#             */
/*   Updated: 2022/06/07 12:40:16 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(t_print *tab)
{
	unsigned long long	i;
	int					count;
	int					padd;

	count = 0;
	i = va_arg(tab->args, unsigned long long);
	if (!i && tab->width)
	{
		padd = tab->width - 5;
		while (padd-- > 0)
			count += write(1, " ", 1);
		tab->ret = count;
		return (-2);
	}
	if (!i)
		return (-2);
	if (tab->leftj)
		return (ft_pleft_align(tab, i));
	if (tab->width)
		return (ft_pprint_width(tab, i));
	count += write(1, "0x", 2);
	return ((ft_put_ptr(tab, i) + count));
}

int	ft_put_ptr(t_print *tab, unsigned long long i)
{
	unsigned long long	temp;

	temp = 0;
	if (i >= 16)
	{
		ft_put_ptr(tab, i / 16);
		ft_put_ptr(tab, i % 16);
	}
	else
	{
		if (i <= 9)
			temp = i + '0';
		else
			temp = i - 10 + 'a';
		tab->ttlen += write(1, &temp, 1);
	}
	return (tab->ttlen);
}

int	ft_pprint_width(t_print *tab, unsigned long long i)
{
	int		count;
	int		padd;
	char	sep;

	count = 0;
	padd = 0;
	sep = ' ';
	padd = tab->width - ft_put_sptr(i) - 2;
	if (tab->leftj)
		return (ft_pleft_align(tab, i));
	while (padd-- > 0)
		count += write(1, &sep, 1);
	if (tab->sp && !tab->sign && i > 0)
		count += write(1, " ", 1);
	count += write(1, "0x", 2);
	return ((ft_put_ptr(tab, i) + count));
}

int	ft_put_sptr(unsigned long long i)
{
	int	count;

	count = 0;
	while (i)
	{
		i /= 16;
		count++;
	}
	return (count);
}

int	ft_pleft_align(t_print *tab, unsigned long long i)
{
	int		count;
	int		padd;
	char	sep;

	count = 0;
	padd = 0;
	sep = ' ';
	padd = tab->width - ft_put_sptr(i) - 2;
	if (tab->sp)
		count += write(1, " ", 1);
	count += write(1, "0x", 2);
	count += ft_put_ptr(tab, i);
	while (padd-- > 0)
		count += write(1, &sep, 1);
	return (count);
}
