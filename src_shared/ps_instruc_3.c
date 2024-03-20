/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instruc_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:13:10 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 14:50:52 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(t_kernel **plug)
{
	roter(&(*plug)->b);
	add_op(plug, "rb");
	(*plug)->prev = RB;
}

void	rr(t_kernel **plug)
{
	roter(&(*plug)->a);
	roter(&(*plug)->b);
	add_op(plug, "rr");
	(*plug)->prev = RR;
	if ((*plug)->readyp)
		comp_plc(plug);
}

void	rra(t_kernel **plug)
{
	rroter(&(*plug)->a);
	add_op(plug, "rra");
	(*plug)->prev = RRA;
	if ((*plug)->readyp)
		comp_plc(plug);
}

void	rrb(t_kernel **plug)
{
	rroter(&(*plug)->b);
	add_op(plug, "rrb");
	(*plug)->prev = RRB;
}

void	rrr(t_kernel **plug)
{
	rroter(&(*plug)->a);
	rroter(&(*plug)->b);
	add_op(plug, "rrr");
	(*plug)->prev = RRR;
	if ((*plug)->readyp)
		comp_plc(plug);
}
