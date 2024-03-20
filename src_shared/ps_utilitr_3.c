/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilitr_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:58:04 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 13:24:31 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sim_r(t_stack *curr, int targ, t_instrset id)
{
	int	res;

	res = 0;
	if (id == RA)
	{
		while (curr->plc != targ)
		{
			res++;
			curr = curr->prev;
		}
	}
	if (id == RRA)
	{
		while (curr->plc != targ)
		{
			res++;
			curr = curr->next;
		}
	}
	return (res);
}

void	apply_plc(t_kernel **plug, t_stack *tmp, t_instrset id)
{
	t_instrset	opt;
	t_instrset	cpt;

	if (id == RA)
	{
		opt = RR;
		cpt = RB;
	}
	else
	{
		opt = RRR;
		cpt = RRB;
	}
	(*plug)->doinstrtms -= tmp->parrall;
	while (tmp->parrall--)
		switchboard(plug, opt);
	while ((*plug)->doinstrtms-- > 0)
		switchboard(plug, cpt);
}

int	add_strmall(t_kernel **plug, t_stack **curr, t_stack **new)
{
	*new = malloc(sizeof(t_stack));
	if (!new)
		terror(plug);
	(*new)->key = (*curr)->key;
	(*new)->nbr = (*curr)->nbr;
	if (!(*plug)->s)
	{
		(*plug)->s = *new;
		(*new)->prev = *new;
		(*new)->next = *new;
		return (1);
	}
	return (0);
}

void	add_op(t_kernel **plug, char *op)
{
	if (!(*plug)->chckr)
		ft_printf("%s\n", op);
}

int	checkdbl(t_kernel *plug)
{
	t_stack	*curr;
	t_stack	*curr2;
	int		temp;
	int		count;
	int		i;

	curr = plug->a;
	count = plug->arcount;
	i = 1;
	while (count--)
	{
		temp = curr->nbr;
		curr2 = curr->next;
		while (count--)
		{
			if (curr2->nbr == temp)
				return (1);
			curr2 = curr2->next;
		}
		count = plug->arcount - i++;
		curr = curr->next;
	}
	return (0);
}
