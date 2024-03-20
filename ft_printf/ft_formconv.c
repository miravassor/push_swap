/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:59:57 by avassor           #+#    #+#             */
/*   Updated: 2022/06/02 17:27:49 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formconv(t_print *tab, const char *pform)
{
	if (*pform == 'c')
		return (ft_print_char(tab));
	else if (*pform == 'd' || *pform == 'i')
		return (ft_print_int(tab));
	else if (*pform == 's')
		return (ft_print_str(tab));
	else if (*pform == 'p')
		return (ft_print_ptr(tab));
	else if (*pform == 'u')
		return (ft_print_uint(tab));
	else if (*pform == 'x' || *pform == 'X')
		return (ft_print_x(tab, pform));
	else if (*pform == '%')
		return (ft_print_perc(tab, pform));
	else
		return (0);
}
