/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:03:42 by avassor           #+#    #+#             */
/*   Updated: 2022/06/07 18:14:50 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <values.h>

typedef struct s_print
{
	va_list	args;
	int		width;
	int		prec;
	int		zeropadd;
	int		point;
	int		leftj;
	int		hash;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
	int		narg;
	int		neg;
	int		ttlen;
	int		ret;
}	t_print;

/* main functions */

int		ft_printf(const char *format, ...);
int		ft_checkerror(t_print *tab, const char *pform);
int		ft_formconv(t_print *tab, const char *pform);

/* printers */

int		ft_print_char(t_print *tab);
int		ft_print_int(t_print *tab);
int		ft_print_str(t_print *tab);
int		ft_print_ptr(t_print *tab);
int		ft_print_uint(t_print *tab);
int		ft_print_x(t_print *tab, const char *pform);
int		ft_print_perc(t_print *tab, const char *pform);

/* int dependencies */

int		ft_count(long c);
int		ft_check_szero(t_print *tab);
int		ft_check_prec(t_print *tab, long c);
int		ft_left_width(t_print *tab, long c);
int		ft_print_prec(t_print *tab, long c);
int		ft_check_sign(t_print *tab, long c);
int		ft_check_intflg(t_print *tab, long c);
int		ft_print_pre(t_print *tab, const char *pform);
int		ft_leftalign(t_print *tab, char *conv, long c);
int		ft_print_width(t_print *tab, char *conv, long c);
int		ft_print_int_end(t_print *tab, int count, char *conv, long c);

char	*ft_itoa(long n);
char	ft_sepid(t_print *tab);

void	ft_checkw(t_print *tab, long c);

/* str dependencies */

int		ft_ret1(t_print *tab);
int		ft_termerrb(t_print *tab);
int		ft_check_strrorb(t_print *tab);
int		ft_termstr(t_print *tab, int count);
int		ft_strprec(t_print *tab, const char *c);
int		ft_check_strprec(t_print *tab, int count);
int		ft_str_printer(t_print *tab, char *conv, long c);
int		ft_check_strrora(t_print *tab, int count, char sep);
int		ft_termerra(t_print *tab, int count, int padd, char sep);
int		ft_strlj(t_print *tab, const char *c, int count, int len);
int		ft_strend(t_print *tab, const char *c, int count, int len);
int		ft_print_strlj(t_print *tab, int count, int len, const char *c);
int		ft_print_str_end(t_print *tab, int count, int len, const char *c);

/* ptr depedencies */

int		ft_put_sptr(unsigned long long i);
int		ft_nstrlen( int count, const char *c);
int		ft_put_ptr(t_print *tab, unsigned long long i);
int		ft_pleft_align(t_print *tab, unsigned long long i);
int		ft_pprint_width(t_print *tab, unsigned long long i);
int		ft_mstrlen(t_print *tab, int count, int padd, const char *c);

/* unsigned depedencies */

int		ft_ucount(unsigned long n);
int		ft_uprinter(const char *conv, int count);
int		ft_print_uprec(t_print *tab, unsigned long c);
int		ft_uleft_width(t_print *tab, char *conv, long c);
int		ft_uprint_width(t_print *tab, char *conv, long c);
int		ft_uleftalign(t_print *tab, char *conv, unsigned long c);
int		ft_print_uend(t_print *tab, unsigned long c, char *conv,
			unsigned int count);

char	*ft_uitoa(unsigned long n);

void	ft_uchecker(t_print *tab, unsigned long a);

/* char depedencies */

int		ft_cleft_align(t_print *tab, char c);

/* hex depedencies */

int		ft_xcount(long n);
int		ft_print_hash(const char *pform);
int		ft_put_xlen(unsigned long long i);
int		ft_print_xprec(t_print *tab, unsigned long long c);
int		ft_put_x(t_print *tab, unsigned long long i, const char *pform);
int		ft_xleft_align(t_print *tab, unsigned long long i, const char *pform);
int		ft_xprint_width(t_print *tab, unsigned long long i, const char *pform);
int		ft_print_xend(t_print *tab, const char *pform, unsigned long long i,
			int count);

void	ft_xcheck(t_print *tab, unsigned long long i);
void	ft_xprintw_check(t_print *tab, unsigned long long i);

/* ID runners */

int		ft_ishash(t_print *tab, const char *pform);
int		ft_isdash(t_print *tab, const char *pform);
int		ft_isplus(t_print *tab, const char *pform);
int		ft_iszero(t_print *tab, const char *pform);
int		ft_isprec(t_print *tab, const char *pform);
int		ft_isperc(t_print *tab, const char *pform);
int		ft_isspace(t_print *tab, const char *pform);
int		ft_iswidth(t_print *tab, const char *pform);

#endif
