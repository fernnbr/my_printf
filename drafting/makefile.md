## NAME = libftprintf.a
Defines the name of the final static library

## SRC = ft_printf.c \ ...
Lists all source .c files (with \ for line continuation)

## CC = cc
Sets the compiler to use (cc → usually gcc or clang).

## CFLAGS = -Wall -Wextra -Werror

1. Compiler options:

2. -Wall:  enable most warnings

3. -Wextra: enable extra warnings

4. -Werror: treat warnings as errors

## AR = ar
Tool used to create static libraries (.a)

## OBJ = $(SRC:.c=.o)
Expands .c files into corresponding .o object files

## all: $(NAME)
Default target: build the library when you type make.

## '$(NAME): $(OBJ)'
Says the library depends on all object files.

## %.o : %.c ft_printf.h

1. Where actual building happens 
2. Pattern rule to build .o from .c.
3. Each .o depends on its .c and the header (ft_printf.h)

## '$<' = source file, 
## '$@' = target file

# Commands:

## '$(CC) $(CFLAGS) -c $< -o $@' 
- compile .c into .o.

## '$(AR) rcs $(NAME) $@'
- add that .o into the archive

# clean:

## rm -f $(OBJ)
- delete all .o files.

## fclean: clean
Runs clean, then rm -f $(NAME) to also remove the library

## re: fclean all
Cleans everything, then rebuilds from scratch

## .PHONY: all clean fclean re

- Declares these as phony targets (not actual files)
- Prevents issues if files named clean/all exist
