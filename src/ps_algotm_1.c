/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algotm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:45:41 by avassor           #+#    #+#             */
/*   Updated: 2022/10/25 10:02:05 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	a_sort(t_kernel **plug, int key1, int key2, int key3)
{
	int	k;
	int	l;
	int	m;

	k = key1;
	l = key2;
	m = key3;
	if (sorted((*plug)->a))
		return ;
	if ((*plug)->a->key == l && (*plug)->a->prev->key == k)
		rra(plug);
	else if ((*plug)->a->key == l && (*plug)->a->next->key == k)
		sa(plug);
	else if ((*plug)->a->key == m && (*plug)->a->next->key == k)
		ra(plug);
	else
	{
		sa(plug);
		if ((*plug)->a->key == m)
			ra(plug);
		else
			rra(plug);
	}
}

void	find_neigh(t_kernel **plug, int key)
{
	t_stack	*curr;
	t_stack	*init;
	t_stack	*temp;

	curr = (*plug)->a;
	init = (*plug)->a->prev;
	temp = (*plug)->dnu;
	while (curr != init)
	{
		if (curr->key < key && curr->key > temp->key)
			temp = curr;
		curr = curr->next;
	}
	if (curr->key < key && curr->key > temp->key)
		temp = curr;
	(*plug)->tmp = temp;
}

void	b_pushback(t_kernel **plug)
{
	if ((*plug)->sizesb > 1)
		if ((*plug)->b->key < (*plug)->b->next->key)
			switchboard(plug, SB);
	while ((*plug)->sizesb)
		switchboard(plug, PA);
}
