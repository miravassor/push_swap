/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilitr_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:03:44 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 13:24:26 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sorted(t_stack *s)
{
	t_stack	*curr;
	t_stack	*curr2;
	t_stack	*last;
	int		temp;

	curr = s;
	last = s->prev;
	while (curr != last)
	{
		temp = curr->nbr;
		curr2 = curr->next;
		while (curr2 != last)
		{
			if (temp > curr2->nbr)
				return (0);
			curr2 = curr2->next;
		}
		if (temp > curr2->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	head_list(t_kernel **plug, t_stack *new)
{
	(*plug)->a = new;
	new->prev = new;
	new->next = new;
	(*plug)->min = new->nbr;
	(*plug)->max = new->nbr;
	(*plug)->tmp = new;
}

int	add_sorted(t_kernel **plug, t_stack *curr)
{
	t_stack	*new;
	t_stack	*tcurr;

	tcurr = (*plug)->s;
	while (tcurr != (*plug)->s->prev)
	{
		if (tcurr == curr)
			return (0);
		tcurr = tcurr->next;
	}
	if (tcurr == curr)
		return (0);
	if (add_strmall(plug, &curr, &new))
		return (1);
	tcurr = (*plug)->s->prev;
	tcurr->next = new;
	new->prev = tcurr;
	new->next = (*plug)->s;
	(*plug)->s->prev = new;
	return (1);
}

void	b_init(t_kernel **plug)
{
	t_stack	*push;

	push = (*plug)->a;
	(*plug)->a = (*plug)->a->next;
	(*plug)->a->prev = push->prev;
	push->prev->next = (*plug)->a;
	(*plug)->b = push;
	(*plug)->b->next = (*plug)->b;
	(*plug)->b->prev = (*plug)->b;
	(*plug)->sizesa--;
	(*plug)->sizesb++;
	add_op(plug, "pb");
	(*plug)->prev = PB;
}
