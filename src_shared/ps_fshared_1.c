/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fshared_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:12:54 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 13:37:04 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_init(t_kernel **plug)
{
	(*plug)->max = 0;
	(*plug)->min = 0;
	(*plug)->med = 0;
	(*plug)->mid = 0;
	(*plug)->sizesa = 0;
	(*plug)->sizesb = 0;
	(*plug)->prev = -1;
	(*plug)->doinstrtms = 0;
	(*plug)->readyp = 0;
	(*plug)->idlist = 0;
	(*plug)->a = NULL;
	(*plug)->b = NULL;
	(*plug)->tmp = NULL;
	(*plug)->arr = NULL;
	(*plug)->dnu = (t_stack *)malloc(sizeof(t_stack));
	if (!(*plug)->dnu)
		terror(plug);
	(*plug)->dnu->key = -1;
	(*plug)->dnu->nbr = 0;
	(*plug)->dnu->next = NULL;
	(*plug)->dnu->prev = NULL;
}

void	addstack(t_kernel **plug, char *argv)
{
	t_stack	*new;
	t_stack	*curr;
	long	temp;

	temp = ft_statoi(&(*plug), argv);
	if (temp > INT_MAX || temp < INT_MIN)
		terror(&(*plug));
	new = malloc(sizeof(t_stack));
	if (!new)
		terror(plug);
	new->nbr = (int)temp;
	if (!(*plug)->a)
		return (head_list(plug, new));
	curr = (*plug)->a->prev;
	curr->next = new;
	new->prev = curr;
	new->next = (*plug)->a;
	(*plug)->a->prev = new;
	if (new->nbr < (*plug)->min)
		(*plug)->min = new->nbr;
	if (new->nbr > (*plug)->max)
	{
		(*plug)->max = new->nbr;
		(*plug)->tmp = new;
	}
}

void	cleaner(t_kernel **plug)
{
	t_chckid	*curr;
	t_chckid	*temp;

	if ((*plug)->a)
		unleash((*plug)->a);
	if ((*plug)->sizesb)
		unleash((*plug)->b);
	if ((*plug)->dnu)
		free((*plug)->dnu);
	if ((*plug)->arr)
		free((*plug)->arr);
	if ((*plug)->idlist)
	{
		curr = (*plug)->idlist;
		while (curr)
		{
			temp = curr->next;
			free(curr->str);
			free(curr);
			if (!temp)
				break ;
			curr = temp;
		}
	}
}

void	unleash(t_stack *x)
{
	t_stack	*hold;
	t_stack	*next;
	t_stack	*temp;

	hold = x;
	temp = x->prev;
	while (hold != temp)
	{
		next = hold->next;
		free(hold);
		hold = next;
	}
	free(temp);
}

long	ft_statoi(t_kernel **plug, char *argv)
{
	char	*p;
	int		sign;
	long	n;

	p = argv;
	sign = 1;
	n = 0;
	while (*p == ' ' || *p == '\f' || *p == '\n' || *p == '\r' || *p == '\t'
		|| *p == '\v' )
		p++;
	if (*p == '-' || *p == '+')
		if (*p++ == '-')
			sign *= -1;
	if (!(*p >= '0' && *p <= '9'))
		terror(plug);
	while (*p >= '0' && *p <= '9')
	{
		n *= 10;
		n += *p - 48;
		p++;
	}
	if (*p)
		terror(plug);
	return (n *= sign);
}
