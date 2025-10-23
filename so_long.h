/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:01:54 by shaun             #+#    #+#             */
/*   Updated: 2025/10/17 01:03:40 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

#define TILE_SIZE 32

typedef struct s_assets
{
	void	*exit;
	void	*wall;
	void	*coin;
	void	*player;
	void	*back;
	char	*exit_str;
	char	*wall_str;
	char	*coin_str;
	char	*player_str;
	char	*back_str;

}	t_assets;

typedef struct s_game
{
	char			**map;
	int				start[3];
	int				exit[3];
	int				width;
	int				depth;
	int				collectible;
}	t_game;

typedef struct s_catalog
{
	int				collectible;
	int				exit[3];
	int				start[3];
	// int				player;
}	t_catalog;

typedef struct s_maze
{
	char			**grid;
	int				i;
	int				j;
	// int				target;
	// int				replacement;
	int				width;
	int				depth;
	int				collectible;
	int				rescue;
	int				result;
	// int				ph;
}	t_maze;

//The structs below are all from push_swap
typedef struct s_node
{
	int				data;
	int				check;
	int				original_pos;
	int				order;
	int				length;
	char			*binstr;
	struct s_node	*next;
}	t_node;

typedef struct s_linkedlist
{
	t_node	*head;
	int		size;
	int		num_operation;
}	t_linkedlist;

void			initialize_assets(void	*mlx, t_assets *pic);
void			init_background(void *mlx, void *win, t_assets *pic, char **map);
void			flood_fill(t_maze *waze, int i, int j);
void			map_display(char **map, t_catalog *c, t_maze *waze);
int				map_check(char **map, t_catalog *c, t_maze *waze);
int				map_catalog(char **map, t_catalog *c, t_maze *waze);
int				borders(char **map);
int				valid_char(char c);
char			**map_translator(char *str);
char			*map_copier(char *str);
int				map_parser(char *str);
//The functions below are all from push_swap
void			radix(t_linkedlist *a, t_linkedlist *b, int index, int size);
void			sort_big_stack(t_linkedlist *a, t_linkedlist *b);
void			labeller(t_linkedlist *list);
void			strrev(char *str);
void			fromdeci(char *binstr, int data, int bytes);
int				simplifier(t_linkedlist *list, int bytes);
void			sa(t_linkedlist *stack_a);
void			sb(t_linkedlist *b);
void			ss(t_linkedlist *a, t_linkedlist *b);
int				pa(t_linkedlist *a, t_linkedlist *b);
int				pb(t_linkedlist *a, t_linkedlist *b);
void			ra(t_linkedlist *a);
void			rb(t_linkedlist *b);
void			rr(t_linkedlist *a, t_linkedlist *b);
void			rra(t_linkedlist *a);
void			rrb(t_linkedlist *b);
void			rrr(t_linkedlist *a, t_linkedlist *b);
void			free_binstr(t_linkedlist *a);
void			free_nodes(t_node *head);

#endif
