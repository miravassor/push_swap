/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:37:37 by mira              #+#    #+#             */
/*   Updated: 2022/06/02 17:42:10 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(t_print *tab, char *conv, long c)
{
	int		count;
	char	sep;

	(void) conv;
	count = 0;
	sep = ' ';
	if (tab->zeropadd && !tab->prec)
		sep = '0';
	ft_checkw(tab, c);
	while (tab->ttlen-- > 0)
		count += write(1, &sep, 1);
	if (tab->sp && !tab->sign && c > 0)
		count += write(1, " ", 1);
	tab->ret = 0;
	return (count);
}

void	ft_checkw(t_print *tab, long c)
{
	if (tab->width == ft_count(c))
		tab->ttlen = 0;
	if (tab->prec > 0 && tab->width > tab->prec)
			tab->ttlen = tab->width - tab->prec - tab->neg - tab->ret;
	else if (tab->prec > 0 && tab->prec < ft_count(c))
		tab->ttlen = 0;
	else if (tab->width > ft_count(c))
			tab->ttlen = tab->width - ft_count(c) - tab->sign - tab->ret;
	else
			tab->ttlen = 0;
}
