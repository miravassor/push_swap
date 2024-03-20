/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruc_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:37:16 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 13:23:53 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sb(t_kernel **plug)
{
	if ((*plug)->sizesb > 1)
	{
		if ((*plug)->sizesb == 2)
			bswaper(&(*plug)->b, &(*plug)->b->next);
		else
			swaper(&(*plug)->b, &(*plug)->b->next);
		add_op(plug, "sb");
		(*plug)->prev = SB;
	}
}

void	ss(t_kernel **plug)
{
	sa(plug);
	sb(plug);
	add_op(plug, "ss");
	(*plug)->prev = SS;
}

void	pa(t_kernel **plug)
{
	t_stack	*push;
	t_stack	*head;
	t_stack	*appp;

	if (!(*plug)->sizesb)
		return ;
	push = (*plug)->b;
	head = (*plug)->a;
	appp = (*plug)->a->prev;
	(*plug)->b = (*plug)->b->next;
	(*plug)->b->prev = push->prev;
	push->prev->next = (*plug)->b;
	(*plug)->a = push;
	(*plug)->a->next = head;
	(*plug)->a->prev = appp;
	head->prev = (*plug)->a;
	appp->next = (*plug)->a;
	(*plug)->sizesa++;
	(*plug)->sizesb--;
	add_op(plug, "pa");
	(*plug)->prev = PA;
	if ((*plug)->readyp)
		comp_plc(plug);
}

void	pb(t_kernel **plug)
{
	t_stack	*push;
	t_stack	*head;
	t_stack	*appp;

	if (!(*plug)->sizesa)
		return ;
	if (!(*plug)->sizesb)
		return (b_init(plug));
	push = (*plug)->a;
	head = (*plug)->b;
	appp = (*plug)->b->prev;
	(*plug)->a = (*plug)->a->next;
	(*plug)->a->prev = push->prev;
	push->prev->next = (*plug)->a;
	(*plug)->b = push;
	(*plug)->b->next = head;
	(*plug)->b->prev = head->prev;
	head->prev = (*plug)->b;
	appp->next = (*plug)->b;
	(*plug)->sizesa--;
	(*plug)->sizesb++;
	add_op(plug, "pb");
	(*plug)->prev = PB;
	if ((*plug)->readyp)
		comp_plc(plug);
}

void	ra(t_kernel **plug)
{
	roter(&(*plug)->a);
	add_op(plug, "ra");
	(*plug)->prev = RA;
	if ((*plug)->readyp)
		comp_plc(plug);
}
