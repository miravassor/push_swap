/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algotm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:45:41 by avassor           #+#    #+#             */
/*   Updated: 2022/10/25 13:56:29 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	b_sort(t_kernel **plug)
{
	while ((*plug)->sizesb != 2)
	{
		if (!(*plug)->a->key || (*plug)->a->nbr == (*plug)->max)
			switchboard(plug, PB);
		else
			switchboard(plug, RA);
	}
	if (!sorted((*plug)->a))
		a_sort(plug, kfndr1(plug), kfndr2(plug), kfndr3(plug));
	if ((*plug)->sizesb)
	{
		if ((*plug)->b->key < (*plug)->b->next->key)
			switchboard(plug, SB);
		switchboard(plug, PA);
		switchboard(plug, RA);
		switchboard(plug, PA);
	}
}

void	comp_iter(t_kernel **plug)
{
	t_stack	*curr;
	t_stack	*last;

	curr = (*plug)->b;
	last = (*plug)->b->prev;
	while (curr != last)
	{
		comp_fcost(plug, curr);
		curr = curr->next;
	}
	comp_fcost(plug, curr);
}

void	comp_fcost(t_kernel **plug, t_stack *curr)
{
	t_instrset	a;
	t_instrset	b;
	int			c;
	int			d;

	c = 0;
	d = 0;
	find_neigh(plug, curr->key);
	a = comp_cost(plug, (*plug)->tmp, (*plug)->sizesa);
	c = (*plug)->doinstrtms;
	b = comp_cost(plug, curr, 1);
	d = (*plug)->doinstrtms;
	if (a == b)
	{
		if (c < d)
			curr->parrall = c;
		else
			curr->parrall = d;
	}
	else
		curr->parrall = 0;
	curr->fcst = c + d;
}

void	place_op(t_kernel **plug)
{
	t_stack	*curr;
	t_stack	*last;
	t_stack	*tmp;

	curr = (*plug)->b;
	last = (*plug)->b->prev;
	tmp = (*plug)->b;
	while (curr != last)
	{
		if (curr->fcst < tmp->fcst)
			tmp = curr;
		curr = curr->next;
	}
	if (curr->fcst < tmp->fcst)
		tmp = curr;
	apply_plc(plug, tmp, comp_cost(plug, tmp, 1));
}
