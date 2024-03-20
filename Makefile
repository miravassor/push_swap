# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:40:21 by avassor           #+#    #+#              #
#    Updated: 2022/11/04 11:04:39 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	= push_swap
CHECKER 	= checker
NAME		= $(PUSH_SWAP)
BONUS		= $(CHECKER)

SRCS_CHECK =	ps_checker_1_bonus.c  	\
				ps_checker_2_bonus.c	\
				ps_checker_3_bonus.c

SRCS_PUSWP =	push_swap.c 			\
				ps_algotm_1.c			\
				ps_algotm_2.c			\
				ps_algotm_3.c			\
				ps_mrgsrt_0.c			\
				ps_solver_0.c

SRCS_SHARD	=	ps_instruc_1.c			\
				ps_instruc_2.c			\
				ps_instruc_3.c			\
				ps_fshared_1.c			\
				ps_fshared_2.c			\
				ps_utilitr_1.c			\
				ps_utilitr_2.c			\
				ps_utilitr_3.c			\
				get_next_line.c 		\
				get_next_line_utils.c	\
				get_next_line_err.c

HEADER 			= inc
PRINTF		 	= ft_printf/ft_printf.a
CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

SRCS_C = $(addprefix src_checker/,${SRCS_CHECK})
SRCS_P = $(addprefix src/,${SRCS_PUSWP})
SRCS_S = $(addprefix src_shared/,${SRCS_SHARD})

OBJS_C = $(SRCS_C:.c=.o)
OBJS_P = $(SRCS_P:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

$(NAME): $(OBJS_P) $(OBJS_S) $(PRINTF)
	$(CC) $(OBJS_P) $(OBJS_S) $(PRINTF) -o $(PUSH_SWAP)

$(BONUS): $(OBJS_C) $(OBJS_S) $(PRINTF)
	$(CC) $(OBJS_C) $(OBJS_S) $(PRINTF) -o $(CHECKER)

$(PRINTF):
	$(MAKE) -s -C ft_printf

all: $(NAME)

bonus: $(BONUS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_C) $(OBJS_P) $(OBJS_S)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(CHECKER) $(PUSH_SWAP) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
