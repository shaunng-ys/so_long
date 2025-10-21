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

typedef struct s_catalog
{
	int				walls;
	int				collectible;
	int				player;
	int				exit;
	int				start;
}	t_catalog;

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

void			map_display(char **map, t_catalog *c);
int				map_check(char **map, t_catalog *c);
int				map_catalog(char **map, t_catalog *c);
int				borders(char **map);
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
