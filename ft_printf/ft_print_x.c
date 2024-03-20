/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:15:15 by avassor           #+#    #+#             */
/*   Updated: 2022/06/07 12:39:55 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(t_print *tab, const char *pform)
{
	unsigned long long	i;
	int					count;

	i = va_arg(tab->args, unsigned int);
	count = 0;
	if (tab->prec >= tab->width)
		tab->width = 0;
	if (tab->prec == -1 && i == 0 && !tab->width)
		return (-3);
	ft_xcheck(tab, i);
	if (tab->prec > 0 && tab->prec < ft_xcount(i) && i != 0)
		tab->prec = 0;
	if (tab->leftj)
		return (ft_xleft_align(tab, i, pform));
	else
		return (ft_print_xend(tab, pform, i, count));
}

int	ft_print_hash(const char *pform)
{
	char	*hash;
	char	*temp;
	int		count;

	count = 0;
	hash = (char *)malloc(sizeof(char) * 3);
	if (!hash)
		return (0);
	temp = hash;
	hash[0] = '0';
	hash[2] = (char)0;
	if (*pform == 'x')
		hash[1] = 'x';
	if (*pform == 'X')
		hash[1] = 'X';
	while (*hash)
		count += write(1, hash++, 1);
	free(temp);
	return (count);
}

int	ft_put_x(t_print *tab, unsigned long long i, const char *pform)
{
	unsigned long long	temp;
	int					w;

	temp = 0;
	if (*pform == 'x')
		w = 'a';
	else
		w = 'A';
	if (i >= 16)
	{
		ft_put_x(tab, i / 16, pform);
		ft_put_x(tab, i % 16, pform);
	}
	else
	{
		if (i <= 9)
			temp = i + '0';
		else
			temp = i - 10 + w;
		tab->ttlen += write(1, &temp, 1);
	}
	return (tab->ttlen);
}

int	ft_xprint_width(t_print *tab, unsigned long long i, const char *pform)
{
	int		count;
	char	sep;

	count = 0;
	sep = ' ';
	if (tab->zeropadd && !tab->prec)
		sep = '0';
	ft_xprintw_check(tab, i);
	while (tab->ttlen-- > 0)
		count += write(1, &sep, 1);
	if (tab->hash)
		count += ft_print_hash(pform);
	tab->ttlen = 0;
	return (count);
}

void	ft_xprintw_check(t_print *tab, unsigned long long i)
{
	if (tab->width == ft_xcount(i))
		tab->ttlen = 0;
	if (tab->prec > 0 && tab->width > tab->prec)
			tab->ttlen = tab->width - tab->prec;
	else if (tab->prec > 0 && tab->prec < ft_xcount(i))
		tab->ttlen = 0;
	else if (tab->width > ft_xcount(i) && tab->width > tab->prec)
		tab->ttlen = tab->width - ft_xcount(i);
	else
		tab->ttlen = 0;
}
