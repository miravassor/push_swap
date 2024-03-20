/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:35:22 by mira              #+#    #+#             */
/*   Updated: 2022/06/08 13:08:28 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(t_print *tab)
{
	const char	*c;
	int			count;
	int			padd;
	int			len;

	count = 0;
	padd = 0;
	c = va_arg(tab->args, char *);
	if (c == NULL && tab->prec == 0 && tab->width <= 6)
		return (-1);
	if (tab->prec == -1)
		return (ft_termstr(tab, count));
	if (!c && tab->width)
		return (ft_termerra(tab, count, padd, ' '));
	if (!c && tab->prec)
		return (ft_termerrb(tab));
	if (!c)
		return (0);
	len = ft_strprec(tab, c);
	if (len == 0 && !tab->width)
		return (0);
	if (tab->leftj)
		return (ft_strlj(tab, c, count, len));
	else
		return (ft_strend(tab, c, count, len));
}

int	ft_termstr(t_print *tab, int count)
{
	if (tab->width > 6)
	{
		tab->width -= 6;
		while (tab->width--)
			count += write(1, " ", 1);
		tab->ret = count;
		return (-1);
	}
	if (tab->width)
	{
		while (tab->width--)
			count += write(1, " ", 1);
		return (count);
	}
	return (0);
}

int	ft_termerra(t_print *tab, int count, int padd, char sep)
{
	padd = tab->width;
	if (tab->prec > tab->width)
	{
		tab->ret = -1;
		return (0);
	}
	if (tab->width > 6)
	{
		tab->width -= 6;
		while (tab->width--)
			count += write(1, " ", 1);
		tab->ret = count;
		return (-1);
	}
	while (padd-- > 0)
		count += write(1, &sep, 1);
	return (count);
}

int	ft_termerrb(t_print *tab)
{
	if (tab->prec >= 6)
		return (-1);
	else
		return (0);
}

int	ft_strprec(t_print *tab, const char *c)
{
	int	count;
	int	len;

	(void) tab;
	count = 0;
	len = 0;
	while (c[count++])
		len++;
	return (len);
}
