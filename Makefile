NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_printf_func.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	cc $(FLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f  $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re