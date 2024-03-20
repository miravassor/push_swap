/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:37:54 by avassor           #+#    #+#             */
/*   Updated: 2022/06/07 17:01:29 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ret0(char *ns)
{
	*ns = '0';
	*(ns + 1) = 0;
	return (ns);
}

char	*ft_itoa(long n)
{
	long	len;
	long	c;
	char	*ns;

	len = ft_count(n);
	c = (long)n;
	ns = (char *)malloc((len + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	if (c == 0)
		return (ret0(ns));
	if (c < 0)
	{
		*ns = '-';
		c *= -1;
	}
	while (c && len)
	{
		*(ns + --len) = (c % 10) + '0';
		c /= 10;
	}
	*(ns + ft_count(n)) = 0;
	return (ns);
}

char	*ft_uitoa(unsigned long n)
{
	unsigned long	len;
	unsigned long	c;
	char			*ns;

	len = ft_ucount((unsigned long )n);
	c = (unsigned long)n;
	ns = (char *)malloc((len + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	if (c == 0)
		return (ret0(ns));
	while (c && len)
	{
		*(ns + --len) = (c % 10) + '0';
		c /= 10;
	}
	*(ns + ft_ucount(n)) = 0;
	return (ns);
}

int	ft_ucount(unsigned long n)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
