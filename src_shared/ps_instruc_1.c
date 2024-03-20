/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruc_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:37:16 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 13:23:32 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swaper(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpp;
	t_stack	*tmpn;

	tmpa = *a;
	tmpp = (*a)->prev;
	tmpn = (*b)->next;
	*a = *b;
	(*a)->prev = tmpp;
	(*a)->next = tmpa;
	tmpa->prev = *a;
	tmpa->next = tmpn;
	tmpp->next = *a;
	tmpn->prev = tmpa;
}

void	bswaper(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *a;
	tmpb = *b;
	*a = *b;
	(*a)->next = tmpa;
	(*a)->prev = tmpa;
	tmpa->prev = tmpb;
	tmpa->next = tmpb;
}

void	roter(t_stack **a)
{
	t_stack	*tmpa;
	t_stack	*tmpp;

	tmpa = *a;
	tmpp = (*a)->prev;
	*a = (*a)->next;
	(*a)->prev = tmpa;
	tmpa->prev = tmpp;
	tmpa->next = *a;
}

void	rroter(t_stack **x)
{
	t_stack	*tmpa;
	t_stack	*tmpp;

	tmpa = *x;
	tmpp = (*x)->prev->prev;
	*x = (*x)->prev;
	(*x)->next = tmpa;
	tmpa->prev = *x;
	tmpp->next = *x;
}

void	sa(t_kernel **plug)
{
	if ((*plug)->sizesa > 1)
	{
		swaper(&(*plug)->a, &(*plug)->a->next);
		add_op(plug, "sa");
		(*plug)->prev = SA;
	}
	if ((*plug)->readyp)
		comp_plc(plug);
}
