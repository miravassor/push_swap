/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:47:15 by avassor           #+#    #+#             */
/*   Updated: 2022/09/21 16:23:10 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->width = 0;
	tab->prec = 0;
	tab->zeropadd = 0;
	tab->point = 0;
	tab->leftj = 0;
	tab->hash = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->sp = 0;
	tab->narg = 0;
	tab->neg = 0;
	tab->ttlen = 0;
	tab->ret = 0;
	return (tab);
}

int	ft_id(char s, char *set)
{
	while (*set)
	{
		if (s == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

int	ft_formid(t_print *tab, const char *pform)
{
	while (!ft_id(*pform, "cspdiuxX%"))
	{
		if (*pform == '#')
			pform += ft_ishash(tab, pform);
		if (*pform == '-')
			pform += ft_isdash(tab, pform);
		if (*pform == '+')
			pform += ft_isplus(tab, pform);
		if (*pform == ' ')
			pform += ft_isspace(tab, pform);
		if (*pform == '0')
			pform += ft_iszero(tab, pform);
		if (*pform >= '0' && *pform <= '9')
			pform += ft_iswidth(tab, pform);
		if (*pform == '.')
			pform += ft_isprec(tab, pform);
	}
	tab->narg += 1;
	if (ft_checkerror(tab, pform))
		return (0);
	else
		return (ft_formconv(tab, pform));
}

int	ft_isperc(t_print *tab, const char *pform)
{
	int	len;
	int	lentemp;

	len = 0;
	lentemp = 0;
	ft_init_tab(tab);
	lentemp = ft_formid(tab, (++pform));
	if (lentemp == -1)
		len += write(1, "(null)", 6);
	else if (lentemp == -2)
		len += write(1, "(nil)", 5);
	else if (lentemp == 0 || lentemp == -3)
		len += 0;
	else
		len += lentemp;
	if (tab->ret == -1)
		len += ft_ret1(tab);
	if (tab->ret)
		len += tab->ret;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_print		*tab;
	const char	*pform;
	int			len;

	pform = format;
	len = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	va_start(tab->args, format);
	while (*pform)
	{
		if (*pform == '%')
		{
			len += ft_isperc(tab, pform);
			pform += tab->narg;
		}
		else
			len += write(1, pform, 1);
		pform++;
	}
	va_end(tab->args);
	free (tab);
	return (len);
}
/*
int	main(void)
{
	// char *s = "test ok ?";
	// char    *tab = "test";
	// int i = 0;
	// char	*i = 255;
	//char i = '\0';
	//char j = '1';
	//char k = 1;
	// printf("og %d\n", printf("%s\n", NULL));
	// printf("mn %d\n", ft_printf("%s\n", NULL));
	// printf("real2:% +-d\n", v);
	// ft_printf("ft_p2:% +-d\n", v);
	// printf("og:%d\n", printf("og:%c, %- 45.46s, %- 20.21d, %u, %x, %p",
	' ', 
	// NULL, -4845, INT_MIN, INT_MIN, NULL));
	// printf("mn:%d\n", ft_printf("mn:%c, %- 45.46s, %- 20.21d, %u, %x, %p",
	' ', 
	// NULL, -4845, INT_MIN, INT_MIN, NULL));
	printf("og:%d\n", printf("og:%-010d\n", 42));
	printf("mn:%d\n", ft_printf("mn:%-010d\n", 42));
	return (0);
}
*/