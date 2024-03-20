/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_align.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:13:29 by mira              #+#    #+#             */
/*   Updated: 2022/06/02 17:44:14 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_leftalign(t_print *tab, char *conv, long c)
{
	int		count;
	int		nprec;
	char	*ctemp;

	count = 0;
	ctemp = conv;
	nprec = 0;
	if (tab->sp && !tab->sign && c > 0)
		count += write(1, " ", 1);
	count += ft_check_sign(tab, c);
	if (tab->sign == 1)
	{
		++conv;
		c *= -1;
	}
	nprec += ft_check_prec(tab, c);
	while (nprec-- > 0)
		count += write(1, "0", 1);
	count += ft_str_printer(tab, conv, c);
	if (tab->width)
		count += ft_left_width(tab, c);
	free(ctemp);
	return (count);
}

int	ft_left_width(t_print *tab, long c)
{
	int		count;
	int		padd;
	char	sep;

	count = 0;
	padd = 0;
	sep = ft_sepid(tab);
	if (tab->prec > 0 && tab->width > tab->prec)
			tab->ttlen = tab->width - tab->prec - tab->sign;
	else if (tab->prec > 0 && tab->prec < ft_count(c))
		tab->ttlen = 0;
	else if (tab->width > ft_count(c) && tab->width > tab->prec)
		tab->ttlen = tab->width - ft_count(c) - tab->sign;
	else
		tab->ttlen = 0;
	padd = tab->ttlen;
	if (tab->sp && !tab->sign && c > 0)
		count += write(1, " ", 1);
	while (padd-- > 0)
		count += write(1, &sep, 1);
	return (count);
}
