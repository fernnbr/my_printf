NAME = libftprintf.a
SRC = ft_printf.c \
      ft_aux_printf.c \
      ft_print_hex.c \
      ft_libft.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) rcs $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
