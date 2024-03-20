/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:08:05 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 13:19:56 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	checkline(t_kernel **plug, char *line)
{
	char		*p;

	p = line;
	if (*p == 's')
		if (*++p == 'a' || *p == 'b' || *p == 's')
			if (*++p == '\n')
				return ;
	p = line;
	if (*p == 'p')
		if (*++p == 'a' || *p == 'b')
			if (*++p == '\n')
				return ;
	p = line;
	if (*p == 'r')
		if (*++p == 'a' || *p == 'b' || *p == 'r')
			if (*++p == '\n')
				return ;
	p = line;
	if (*p == 'r')
		if (*++p == 'r')
			if (*++p == 'a' || *p == 'b' || *p == 'r')
				if (*++p == '\n')
					return ;
	free(line);
	terror(plug);
}

int	checker(t_kernel **plug, char **argv)
{
	int	i;

	i = 1;
	while (i <= (*plug)->arcount)
		addstack(plug, argv[i++]);
	if (checkdbl((*plug)))
		terror(plug);
	(*plug)->sizesa = (*plug)->arcount;
	return (do_check(plug));
}

void	cerror(t_kernel **plug)
{
	write(2, "Error\n", 6);
	terror(plug);
}

int	main(int argc, char **argv)
{
	t_kernel	*plug;

	if (argc < 2)
		return (1);
	plug = malloc(sizeof(t_kernel));
	if (!plug)
		terror(&plug);
	plug->a = NULL;
	plug->arcount = argc - 1;
	push_init(&plug);
	plug->chckr = 1;
	checker(&plug, argv);
	cleaner(&plug);
	free(plug);
	return (0);
}
