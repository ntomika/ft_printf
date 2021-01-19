
FLAGS 		= -Wall -Werror -Wextra -g

NAME		= libftprintf.a

INCLUDE		= -I ./

SRC			= ft_printf.c check_all.c ft_itoa.c ft_print_int.c \
			ft_print_symbol.c ft_printf_utils.c ft_print_unsigned.c \
			ft_print_string.c main.c

OBJS 		= $(SRC:.c=.o)

all: 		$(NAME)

.c.o:
			gcc $(FLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			@rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re

debug:
			gcc -g *.c