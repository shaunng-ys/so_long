# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 00:44:12 by shaun             #+#    #+#              #
#    Updated: 2025/10/17 00:44:58 by shaun             ###   ########kl        #
#                                                                              #
# **************************************************************************** #

# Important terms/concepts: Targets, prerequisites, variables & commands.

# Variables below:

FLAGS = -Wall -Werror -Wextra 

LIB = libft/libft.a 

NAME = so_long

INC = so_long.h

SRC = string_checker.c add_to_stack.c operations1.c operations2.c operations3.c\
	push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap.c\
	decibase.c normalizer.c

OBJ = string_checker.o add_to_stack.o operations1.o operations2.o operations3.o\
	push_swap_utils1.o push_swap_utils2.o push_swap_utils3.o push_swap.o\
	decibase.o normalizer.o

# Targets & dependencies below:

all: $(NAME)

$(LIB):
	make -C libft

$(OBJ):
	cc -c $(SRC)

$(NAME): $(OBJ) $(LIB)
	cc $(FLAGS) -I $(INC) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean re all
