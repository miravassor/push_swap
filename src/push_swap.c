/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:53:35 by avassor           #+#    #+#             */
/*   Updated: 2022/11/04 11:03:49 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	argchck(char *arg)
{
	char	*p;

	p = arg;
	if (*p == '-' || *p == '+')
		p++;
	while (*p)
	{
		if (!(*p >= '0' && *p <= '9'))
			return (1);
		p++;
	}
	return (0);
}

int	errarg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argchck(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	strt_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	push_swap(t_kernel **plug, char **argv)
{
	int	i;

	i = 1;
	while (i <= (*plug)->arcount)
		addstack(plug, argv[i++]);
	if (checkdbl((*plug)))
		terror(plug);
	if (sorted((*plug)->a))
		tsorted(plug);
	(*plug)->sizesa = (*plug)->arcount;
	copy_to_array(plug);
	mrgsort(plug, (*plug)->arr, 0, ((*plug)->arcount - 1));
	(*plug)->mid = ((*plug)->tmp->key / 2) + 1;
	solver(plug);
	return (0);
}

int	main(int argc, char **argv)
{
	t_kernel	*plug;

	plug = malloc(sizeof(t_kernel));
	if (!plug)
		strt_error();
	push_init(&plug);
	plug->chckr = 0;
	if (errarg(argc, argv))
		terror(&plug);
	if (argc < 3)
	{
		free(plug->dnu);
		free(plug);
		return (1);
	}
	plug->a = NULL;
	plug->arcount = argc - 1;
	push_swap(&plug, argv);
	cleaner(&plug);
	free(plug);
	return (0);
}
