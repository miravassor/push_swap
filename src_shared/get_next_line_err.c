/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:31:20 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 15:01:00 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	ft_checklinea(t_stash **stash, char *line)
{
	char	*p;

	p = line;
	if (!*p)
		return (0);
	if (!ft_checkiter(line))
		return (0);
	if ((*stash))
		ft_unleash(*stash);
	stash = NULL;
	return (1);
}

int	ft_checkiter(char *line)
{
	char	*p;

	p = line;
	if (*p == 's')
		if (*++p == 'a' || *p == 'b' || *p == 's')
			if (*++p == '\n')
				return (0);
	p = line;
	if (*p == 'p')
		if (*++p == 'a' || *p == 'b')
			if (*++p == '\n')
				return (0);
	p = line;
	if (*p == 'r')
		if (*++p == 'a' || *p == 'b' || *p == 'r')
			if (*++p == '\n')
				return (0);
	p = line;
	if (*p == 'r')
		if (*++p == 'r')
			if (*++p == 'a' || *p == 'b' || *p == 'r')
				if (*++p == '\n')
					return (0);
	return (1);
}
