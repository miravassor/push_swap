/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:16 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 13:12:36 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_instrset	arr_conv(t_chckid *curr)
{
	char		*p;
	int			i;
	t_instrset	id;

	i = 0;
	p = curr->str;
	id = NUL;
	while (*p >= 'a' && *p <= 'z')
		i += *p++;
	if (i == ('s' + 'a'))
	{
		if (*curr->str == 's')
			id = SA;
		else
			id = RB;
	}
	else if (i == ('s' + 'b'))
		id = SB;
	else if (i == ('s' + 's'))
		id = SS;
	if (id != NUL)
		return (id);
	else
		return (arr_conv2(id, i));
}

t_instrset	arr_conv2(t_instrset id, int i)
{
	if (i == ('p' + 'a'))
		id = PA;
	else if (i == ('p' + 'b'))
		id = PB;
	else if (i == ('r' + 'a'))
		id = RA;
	else if (i == ('r' * 2))
		id = RR;
	else if (i == (('r' * 2) + 'a'))
		id = RRA;
	else if (i == (('r' * 2) + 'b'))
		id = RRB;
	else
		id = RRR;
	return (id);
}

void	apply_sort(t_kernel **plug)
{
	t_chckid	*curr;

	curr = (*plug)->idlist;
	while (curr)
	{
		switchboard(plug, curr->convid);
		curr = curr->next;
	}
}

int	final_check(t_kernel **plug)
{
	if ((*plug)->sizesb || !sorted((*plug)->a))
	{
		ft_printf("KO\n");
		return (0);
	}
	else if (!(*plug)->sizesb && sorted((*plug)->a))
	{
		ft_printf("OK\n");
		return (0);
	}
	return (1);
}

int	do_check(t_kernel **plug)
{
	char	*p;
	int		i;

	i = 0;
	p = get_next_line(i);
	if (p)
		if (*p == 'T')
			terror(plug);
	while (addinstr(plug, p))
	{
		p = get_next_line(0);
		if (p)
			if (*p == 'T')
				terror(plug);
	}
	conv_id(plug);
	apply_sort(plug);
	return (final_check(plug));
}
