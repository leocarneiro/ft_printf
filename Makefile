# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 16:59:43 by lramos-r          #+#    #+#              #
#    Updated: 2020/03/12 17:32:46 by lramos-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC			= calc_fields.c field_flags.c field_precision.c field_types.c \
				field_width.c ft_isnumber.c ft_itoa_base.c ft_memmove.c \
				ft_memset.c ft_printf.c ft_printnbr.c ft_putchar.c ft_putstr.c \
				ft_strchr.c ft_strcmp.c ft_strdup.c ft_strlen.c ft_strnew.c \
				ft_strupcase.c init_counters.c type_c.c type_d.c type_p.c \
				type_s.c type_u.c type_x.c

OBJ			= $(SRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror

H			= printf.h

all:$(NAME)

$(NAME):
		gcc -c $(FLAG) $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all

norm:
		norminette -CheckForbiddenSourceHeader *.[ch]
