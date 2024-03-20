/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algotm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:13:54 by avassor           #+#    #+#             */
/*   Updated: 2022/10/25 10:06:29 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	c_sort(t_kernel **plug)
{
	int	thresh;

	thresh = 0;
	if ((*plug)->sizesa <= 100)
		thresh = 2;
	else
		thresh = 3;
	(*plug)->med = ((*plug)->sizesa / thresh);
	split_sort(plug, thresh);
	comp_plc(plug);
	(*plug)->readyp = 1;
	final_sort(plug);
	head_fndr(plug);
}

void	split_sort(t_kernel **plug, int shift)
{
	int	count;
	int	thresh;

	if (!shift)
		return ;
	count = 0;
	thresh = shift;
	while (count < ((*plug)->arcount / thresh) - 1)
	{
		if ((*plug)->sizesa == 2)
			return ;
		if ((*plug)->a->key && ((*plug)->a->key <= (*plug)->med)
			&& ((*plug)->a->nbr != (*plug)->max))
		{
			switchboard(plug, PB);
			count++;
			continue ;
		}
		switchboard(plug, RA);
	}
	(*plug)->med += (*plug)->med;
	split_sort(plug, shift);
}

void	final_sort(t_kernel **plug)
{
	t_instrset	instr;

	while ((*plug)->sizesb)
	{
		comp_plc(plug);
		if ((*plug)->sizesb > 1)
			comp_iter(plug);
		place_op(plug);
		comp_plc(plug);
		find_neigh(plug, (*plug)->b->key);
		instr = comp_cost(plug, (*plug)->tmp, (*plug)->sizesa);
		while ((*plug)->doinstrtms--)
			switchboard(plug, instr);
		switchboard(plug, PA);
	}
}
