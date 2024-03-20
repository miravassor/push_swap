/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:58:06 by avassor           #+#    #+#             */
/*   Updated: 2022/10/31 14:59:02 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef enum e_instrset
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NUL
}	t_instrset;

typedef struct s_stack
{
	struct s_stack	*prev;
	int				nbr;
	int				key;
	int				plc;
	int				tplc;
	int				fcst;
	int				parrall;
	t_instrset		id;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chckid
{
	char			*str;
	t_instrset		convid;
	struct s_chckid	*next;
}	t_chckid;

typedef struct s_kernel
{
	int			*arr;
	int			max;
	int			min;
	int			med;
	int			mid;
	int			sizesa;
	int			sizesb;
	int			arcount;
	int			readyp;
	int			doinstrtms;
	int			chckr;
	char		*line;
	t_stack		*a;
	t_stack		*b;
	t_stack		*s;
	t_stack		*tmp;
	t_stack		*dnu;
	t_chckid	*idlist;
	t_instrset	prev;
}	t_kernel;

/*===================MAIN FUNCTION====================*/

int			push_swap(t_kernel **plug, char **argv);

/*===================PARSING===========================*/

long		ft_statoi(t_kernel **plug, char *argv);

void		addstack(t_kernel **plug, char *argv);
void		head_list(t_kernel **plug, t_stack *new);

/*===================ALGORITHM=========================*/

void		solver(t_kernel **plug);
void		comp_plc(t_kernel **plug);
void		head_fndr(t_kernel **plug);
void		final_sort(t_kernel **plug);
void		find_neigh(t_kernel **plug, int key);
void		split_sort(t_kernel **plug, int shift);

void		merger(int *temp, int *lst, int in, int out);
void		copy_left(int *lst, int *temp, int in, int out);
void		mrgsort(t_kernel **plug, int *lst, int in, int out);
void		mrgfrst(t_kernel **plug, int *size, int out, int **temp);

void		a_sort(t_kernel **plug, int key1, int key2, int key3);
void		b_sort(t_kernel **plug);
void		c_sort(t_kernel **plug);

t_instrset	comp_cost(t_kernel **plug, t_stack *strt, int targ);

/*===================INSTRUCTIONS======================*/

void		bswaper(t_stack **a, t_stack **b);
void		swaper(t_stack **a, t_stack **b);
void		rroter(t_stack **a);
void		roter(t_stack **a);

void		sa(t_kernel **plug);
void		sb(t_kernel **plug);
void		ss(t_kernel **plug);
void		pa(t_kernel **plug);
void		pb(t_kernel **plug);
void		ra(t_kernel **plug);
void		rb(t_kernel **plug);
void		rr(t_kernel **plug);
void		rra(t_kernel **plug);
void		rrb(t_kernel **plug);
void		rrr(t_kernel **plug);

/*===================UTILITIES=========================*/

int			argchck(char *arg);
int			sorted(t_stack *s);
int			kfndr1(t_kernel **plug);
int			kfndr2(t_kernel **plug);
int			kfndr3(t_kernel **plug);
int			checkdbl(t_kernel *plug);
int			errarg(int argc, char **argv);
int			add_sorted(t_kernel **plug, t_stack *curr);
int			sim_r(t_stack *curr, int targ, t_instrset id);
int			add_strmall(t_kernel **plug, t_stack **curr, t_stack **new);

void		add_op(t_kernel **plug, char *op);
void		b_init(t_kernel **plug);
void		add_keys(t_kernel **plug);
void		place_op(t_kernel **plug);
void		comp_iter(t_kernel **plug);
void		push_init(t_kernel **plug);
void		b_pushback(t_kernel **plug);
void		copy_to_array(t_kernel **plug);
void		comp_fcost(t_kernel **plug, t_stack *curr);
void		switchboard(t_kernel **plug, t_instrset id);
void		apply_plc(t_kernel **plug, t_stack *tmp, t_instrset id);

/*===================TERMINATE=========================*/

int			tsorted(t_kernel **plug);

void		strt_error(void);
void		terror(t_kernel **plug);
void		cleaner(t_kernel **plug);
void		unleash(t_stack *x);
void		terminate(t_kernel **plug);

/*===================CHECKER===========================*/

int			my_strlen(char *line);
int			do_check(t_kernel **plug);
int			final_check(t_kernel **plug);
int			checker(t_kernel **plug, char **argv);
int			addinstr(t_kernel **plug, char *line);
int			head_id(t_kernel **plug, t_chckid *new, char *line);

void		cerror(t_kernel **plug);
void		conv_id(t_kernel **plug);
void		apply_sort(t_kernel **plug);
void		checkline(t_kernel **plug, char *line);
void		copy_line(t_kernel **plug, t_chckid *new, char *line);

t_instrset	arr_conv(t_chckid *curr);
t_instrset	arr_conv2(t_instrset id, int i);

#endif
