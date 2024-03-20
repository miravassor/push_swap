/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fshared_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:12:58 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 14:51:26 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	terror(t_kernel **plug)
{
	write(2, "Error\n", 6);
	cleaner(plug);
	free((*plug));
	exit (1);
}

int	tsorted(t_kernel **plug)
{
	cleaner(plug);
	free((*plug));
	exit (0);
}

void	head_fndr(t_kernel **plug)
{
	t_stack		*curr;
	t_instrset	instr;

	if (sorted((*plug)->a))
		return ;
	curr = (*plug)->a;
	while (curr->key)
		curr = curr->next;
	(*plug)->tmp = curr;
	instr = comp_cost(plug, (*plug)->tmp, 1);
	while ((*plug)->doinstrtms--)
		switchboard(plug, instr);
}

t_instrset	comp_cost(t_kernel **plug, t_stack *strt, int targ)
{
	t_stack	*curr;
	int		ra;
	int		rra;

	curr = strt;
	ra = sim_r(curr, targ, RA);
	rra = sim_r(curr, targ, RRA);
	if (ra < rra)
	{
		(*plug)->doinstrtms = ra;
		return (RA);
	}
	else
		(*plug)->doinstrtms = rra;
	return (RRA);
}
