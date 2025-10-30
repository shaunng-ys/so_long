# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sng <sng@student.42kl.edu.my>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 00:44:12 by shaun             #+#    #+#              #
#    Updated: 2025/10/30 14:23:02 by sng              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Important terms/concepts: Targets, prerequisites, variables & commands.

# Variables below:

FLAGS = -Wall -Werror -Wextra -g3

CC = cc

LIB = libft/libft.a 

NAME = so_long

INC = so_long.h

SRC = asset_loader.c end_program.c keypress.c map_logic.c so_long.c\
flood_fill.c map_index.c map_parser.c utils.c

OBJ = $(SRC:.c=.o)

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
	$(CC) $(FLAGS) -c $< -o $@
#	$(CC) $(FLAGS) -Imlx -I /usr/X11R6/include -c $< -o $@
#$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) -I $(INC) $(OBJ) $(LIB) -Lminilibx-linux -lmlx -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
#	$(CC) $(FLAGS) -I $(INC) $(OBJ) $(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#	$(CC) $(FLAGS) -I $(INC) $(LIB) $(OBJ) -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#	$(CC) $(FLAGS) -I $(INC) $(LIB) $(OBJ) -Lmlx -L /usr/X11R6/lib  -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -arch arm64 -o $(NAME)
#$(CC) $(FLAGS) -I $(INC) $(OBJ) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -framework Cocoa -arch arm64 -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean re all
