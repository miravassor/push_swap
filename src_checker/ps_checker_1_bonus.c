/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:16 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 14:22:59 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	my_strlen(char *line)
{
	char	*p1;
	int		cnt;

	p1 = line;
	cnt = 0;
	while (*p1++)
		cnt++;
	return (cnt);
}

void	copy_line(t_kernel **plug, t_chckid *new, char *line)
{
	char	*p1;
	char	*p2;

	p2 = line;
	new->str = malloc(sizeof(char) * (my_strlen(line) + 1));
	if (!new->str)
		terror(plug);
	p1 = new->str;
	while (*p2 && *p2 != '\n')
		*p1++ = *p2++;
	*p1 = '\0';
	free(line);
}

int	head_id(t_kernel **plug, t_chckid *new, char *line)
{
	(*plug)->idlist = new;
	new->next = NULL;
	copy_line(plug, new, line);
	return (1);
}

int	addinstr(t_kernel **plug, char *line)
{
	t_chckid	*new;
	t_chckid	*curr;

	if (!line)
		return (0);
	checkline(plug, line);
	new = malloc(sizeof(t_chckid));
	if (!new)
		terror(plug);
	if (!(*plug)->idlist)
		return (head_id(plug, new, line));
	curr = (*plug)->idlist;
	while (curr)
	{
		if (!curr->next)
			break ;
		curr = curr->next;
	}
	curr->next = new;
	new->next = NULL;
	copy_line(plug, new, line);
	return (1);
}

void	conv_id(t_kernel **plug)
{
	t_chckid	*curr;

	curr = (*plug)->idlist;
	while (curr)
	{
		curr->convid = arr_conv(curr);
		curr = curr->next;
	}
}
