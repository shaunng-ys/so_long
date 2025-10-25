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
# include "mlx_linux/mlx.h"
# include <fcntl.h>

# define TILE 64

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

typedef struct s_maze
{
	char			**grid;
	int				i;
	int				j;
	int				width;
	int				depth;
	int				collectible;
	int				rescue;
	int				result;
}	t_maze;

// typedef struct s_catalog
// {
// 	int				coins;
// 	int				exit[3];
// 	int				start[3];
// 	t_maze			*waze;
// }	t_catalog;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	int				map_valid;
	int				i;
	int				j;
	int				width;
	int				depth;
	int				coins;
	int				exit[3];
	int				start[3];
	t_maze			*waze;
	t_assets		*pic;
	// t_catalog		*c;
	// t_maze			*waze;
}	t_game;

void			init(t_game *info, t_assets *image, t_maze *waze, char **map);
void			g_init(t_game *info, t_assets *img, t_maze *waze, char **map);
int				map_logic(t_maze *waze, t_game *info, char *map_str);
int				add_to_catalog(t_game *info, char **map, int i, int j);
int				close_shop(t_game *info);
void			move_up(t_game *info);//, int i, int j);
void			move_down(t_game *info);//, int i, int j);
void			move_left(t_game *info);//, int i, int j);
void			move_right(t_game *info);//, int i, int j);
int				conditions(int key, t_game *info);
void			initialize_assets(void	*mlx, t_assets *pic);
void			init_backg(void *mlx, void *win, t_assets *pic, char **map);
void			flood_fill(t_maze *waze, int i, int j);
void			map_display(char **map, t_game *info, t_maze *waze);
int				map_check(char **map, t_game *info, t_maze *waze);
int				map_catalog(char **map, t_game *info, t_maze *waze);
int				borders(char **map, size_t l);
int				valid_char(char c);
char			**map_translator(char *str);
char			*map_copier(char *str);
int				map_parser(char *str);

#endif
