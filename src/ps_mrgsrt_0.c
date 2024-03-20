/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_doutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:48:14 by avassor           #+#    #+#             */
/*   Updated: 2022/10/20 15:55:51 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	merger(int *temp, int *lst, int in, int out)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = in + 1;
	while (j <= in)
	{
		if (k > out || temp[j] <= lst[k])
			lst[i++] = temp[j++];
		else
			lst[i++] = lst[k++];
	}
}

void	copy_left(int *lst, int *temp, int in, int out)
{
	while (in <= out)
	{
		temp[in] = lst[in];
		in++;
	}
}

void	mrgsort(t_kernel **plug, int *lst, int in, int out)
{
	int			mid;
	static int	size;
	static int	*temp = NULL;

	if (in >= out)
		return ;
	if (!temp)
		mrgfrst(plug, &size, out, &temp);
	mid = (in + out) / 2;
	mrgsort(plug, lst, in, mid);
	mrgsort(plug, lst, mid + 1, out);
	if (lst[mid] > lst[mid + 1])
	{
		copy_left(lst, temp, in, mid);
		merger(temp + in, lst + in, mid - in, out - in);
	}
	if (out + 1 == size && in == 0)
	{
		free(temp);
		add_keys(plug);
	}
	return ;
}

void	mrgfrst(t_kernel **plug, int *size, int out, int **temp)
{
	*size = out + 1;
	*temp = malloc(sizeof(int) * *size);
	if (!temp)
		terror(plug);
}
