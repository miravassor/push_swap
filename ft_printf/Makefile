# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 13:03:15 by avassor           #+#    #+#              #
#    Updated: 2022/10/06 16:27:56 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c \
			ft_formconv.c \
			ft_itoa.c \
			ft_left_align.c \
			ft_print_char.c \
			ft_print_int.c \
			ft_print_perc.c \
			ft_print_ptr.c \
			ft_print_str.c \
			ft_print_uint.c \
			ft_print_width.c \
			ft_print_x.c \
			ft_print_xprec.c \
			ft_utilities.c \
			ft_idrunner.c \
			ft_checker.c \
			ft_idprinter.c  \
			ft_print_str2.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	ft_printf.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus: all

.PHONY:		all clean fclean re
