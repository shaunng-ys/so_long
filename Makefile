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

FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

CC = cc

LIB = libft/libft.a 

NAME = so_long

INC = so_long.h

SRC = $(wildcard *.c)
#string_checker.c add_to_stack.c operations1.c operations2.c operations3.c\
push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap.c\
decibase.c normalizer.c

OBJ = $(SRC:.c=.o)
#string_checker.o add_to_stack.o operations1.o operations2.o operations3.o\
push_swap_utils1.o push_swap_utils2.o push_swap_utils3.o push_swap.o\
decibase.o normalizer.o

# Targets & dependencies below:

all: $(NAME)

$(LIB):
	make -C libft

#$@ is: The file name of the target of the rule.
#If the target is an archive member, then ‘$@’ is the name of the archive file.
#In a pattern rule that has multiple targets (see Introduction to Pattern Rules), ‘$@’ is the name of whichever target caused the rule's recipe to be run.

#$< is: The name of the first prerequisite.
#If the target got its recipe from an implicit rule, this will be the first prerequisite added by the implicit rule.

# Both target and dependencies below are from the minilibx guide from https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
%.o: %.c
	$(CC) $(FLAGS) -Imlx -I /usr/X11R6/include -c $< -o $@
#$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) -I $(INC) $(LIB) $(OBJ) -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#	$(CC) $(FLAGS) -I $(INC) $(LIB) $(OBJ) -Lmlx -L /usr/X11R6/lib  -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -arch arm64 -o $(NAME)
#$(CC) $(FLAGS) -I $(INC) $(OBJ) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -framework Cocoa -arch arm64 -o $(NAME)

#$(OBJ):
#	cc -c $(SRC)

#$(NAME): $(OBJ) $(LIB)
#	cc $(FLAGS) -I $(INC) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean re all
