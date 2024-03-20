/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:35:49 by avassor           #+#    #+#             */
/*   Updated: 2022/10/24 12:31:56 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	copy_to_array(t_kernel **plug)
{
	int		i;
	int		count;
	t_stack	*curr;

	(*plug)->arr = malloc(sizeof(int) * ((*plug)->arcount + 1));
	if (!((*plug)->arr))
		terror(plug);
	i = 0;
	curr = (*plug)->a;
	count = (*plug)->arcount;
	while (count--)
	{
		(*plug)->arr[i++] = curr->nbr;
		if (!count)
			break ;
		curr = curr->next;
	}
	(*plug)->arr[i] = '\0';
}

void	add_keys(t_kernel **plug)
{
	int		i;
	int		counter;
	int		*curr;
	t_stack	*s_curr;

	i = 0;
	s_curr = (*plug)->a;
	while (i < (*plug)->arcount)
	{
		curr = (*plug)->arr;
		counter = 0;
		while (curr - (*plug)->arr < (*plug)->arcount)
		{
			if (s_curr->nbr == *curr)
			{
				s_curr->key = counter;
				break ;
			}
			counter++;
			curr++;
		}
		s_curr = s_curr->next;
		i++;
	}
}

void	solver(t_kernel **plug)
{
	if ((*plug)->arcount <= 3)
		a_sort(plug, 0, 1, 2);
	else if ((*plug)->arcount <= 5)
		b_sort(plug);
	else
		c_sort(plug);
}
