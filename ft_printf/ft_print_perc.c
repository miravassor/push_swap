/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:32:52 by avassor           #+#    #+#             */
/*   Updated: 2022/06/02 15:26:25 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_perc(t_print *tab, const char *pform)
{
	(void) tab;
	if (*pform == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
