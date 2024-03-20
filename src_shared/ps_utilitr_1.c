/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilitr_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:13:14 by avassor           #+#    #+#             */
/*   Updated: 2022/11/04 11:01:43 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	switchboard(t_kernel **plug, t_instrset id)
{
	void	(*fptr[11])(t_kernel **);

	fptr[SA] = sa;
	fptr[SB] = sb;
	fptr[SS] = ss;
	fptr[PA] = pa;
	fptr[PB] = pb;
	fptr[RA] = ra;
	fptr[RB] = rb;
	fptr[RR] = rr;
	fptr[RRA] = rra;
	fptr[RRB] = rrb;
	fptr[RRR] = rrr;
	((*fptr[id])(plug));
}

int	kfndr1(t_kernel **plug)
{
	t_stack	*curr;
	int		key;

	curr = (*plug)->a;
	key = (*plug)->a->key;
	while (curr != (*plug)->a->prev)
	{
		if (curr->key < key)
			key = curr->key;
		curr = curr->next;
	}
	if (curr->key < key)
			key = curr->key;
	return (key);
}

int	kfndr2(t_kernel **plug)
{
	t_stack	*curr;
	int		key;
	int		keymx;
	int		keymn;

	key = 0;
	keymx = kfndr3(plug);
	keymn = kfndr1(plug);
	curr = (*plug)->a;
	while (curr != (*plug)->a->prev)
	{
		if (curr->key < keymx && curr->key > keymn)
			key = curr->key;
		curr = curr->next;
	}
	if (curr->key < keymx && curr->key > keymn)
			key = curr->key;
	return (key);
}

int	kfndr3(t_kernel **plug)
{
	t_stack	*curr;
	int		key;

	curr = (*plug)->a;
	key = (*plug)->a->key;
	while (curr != (*plug)->a->prev)
	{
		if (curr->key > key)
			key = curr->key;
		curr = curr->next;
	}
	if (curr->key > key)
			key = curr->key;
	return (key);
}

void	comp_plc(t_kernel **plug)
{
	t_stack	*curr;
	t_stack	*last;
	int		count;

	curr = (*plug)->a;
	last = (*plug)->a->prev;
	count = 1;
	while (curr != last)
	{
		curr->plc = count++;
		curr = curr->next;
	}
	curr->plc = count++;
	curr = (*plug)->b;
	last = (*plug)->b->prev;
	count = 1;
	while (curr != last)
	{
		curr->plc = count++;
		curr = curr->next;
	}
	curr->plc = count++;
}
