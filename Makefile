# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntomika <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 20:14:10 by ntomika           #+#    #+#              #
#    Updated: 2021/01/23 20:24:25 by ntomika          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 		= -Wall -Wextra -Werror

NAME		= libftprintf.a

SRC			= ft_printf.c check_all.c ft_itoa.c ft_print_int.c \
			ft_print_symbol.c ft_printf_utils.c ft_print_unsigned.c \
			ft_print_string.c ft_print_16x.c ft_print_pointer.c  \
			ft_flags_123.c ft_strdup.c ft_print_void.c ft_dop_string.c

OBJS 		= $(SRC:.c=.o)

all: 		$(NAME)

.c.o:
			gcc $(FLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			@rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
