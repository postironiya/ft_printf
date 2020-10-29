# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 12:56:59 by rmarguri          #+#    #+#              #
#    Updated: 2020/07/31 23:29:38 by rmarguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COMP = clang

FLAGS = -Wall -Wextra -Werror

SRC =	./src/ft_assemble.c ./src/ft_base.c ./src/ft_collectdata.c \
./src/ft_output_char.c ./src/ft_output_str.c ./src/ft_output_p.c \
./src/ft_output_int.c ./src/ft_output_uint.c ./src/ft_output_shex.c \
./src/ft_output_bhex.c ./src/ft_output_pct.c ./src/ft_output_utils.c \
./ft_printf.c ./ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar -rcs $(NAME) $(OBJ)

%.o: %.c
	@$(COMP) $(FLAGS) -c $< -o $@

go:
	clang main.c $(NAME)
	./a.out

clean:
	@rm -rf *.o ./src/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, go, re, clean, fclean