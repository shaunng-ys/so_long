/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:34:22 by shaun             #+#    #+#             */
/*   Updated: 2025/10/23 02:34:23 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function for initializing the assets
// void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
void	initialize_assets(void	*mlx, t_assets *pic)
{
	int	width;
	int	height;

	pic->exit_str = "assets/exit/Chicken.xpm";
	pic->wall_str = "assets/wall/Oak_Tree.xpm";
	pic->coin_str = "assets/collectible/eggs_brown.xpm";
	pic->player_str = "assets/player/Player.xpm";
	pic->back_str = "assets/background/color_background_1.xpm";

	pic->exit = mlx_xpm_file_to_image(mlx, pic->exit_str, &width, &height);
	pic->wall = mlx_xpm_file_to_image(mlx, pic->wall_str, &width, &height);
	pic->coin = mlx_xpm_file_to_image(mlx, pic->coin_str, &width, &height);
	pic->player = mlx_xpm_file_to_image(mlx, pic->player_str, &width, &height);
	pic->back = mlx_xpm_file_to_image(mlx, pic->back_str, &width, &height);
}

void	init_background(void *mlx, void *win, t_assets *pic, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			mlx_put_image_to_window(mlx, win, pic->back, j * TILE_SIZE, i * TILE_SIZE);
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, pic->wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, pic->coin, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, pic->player, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, pic->exit, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
// void *load_image(void *mlx, char *path)
// {
// 	int w, h;
// 	void *img = mlx_xpm_file_to_image(mlx, path, &w, &h);
// 	if (!img)
// 		perror(path);
// 	else
// 		printf("Loaded %s (%dx%d)\n", path, w, h);
// 	return img;
// }

// void initialize_assets(void *mlx, t_assets *pic)
// {
// 	pic->exit = load_image(mlx, "./assets/exit/Chicken.xpm");
// 	pic->wall = load_image(mlx, "./assets/wall/Fences.xpm");
// 	pic->coin = load_image(mlx, "./assets/collectible/eggs_brown.xpm");
// 	pic->player = load_image(mlx, "./assets/player/Player.xpm");
// 	pic->back = load_image(mlx, "./assets/background/space.xpm");
// }

// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
// void	init_background(void *mlx, void *win, t_assets *pic, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			// mlx_put_image_to_window(mlx, win, pic->back, i * TILE_SIZE, j * TILE_SIZE);
// 			if (map[i][j] == '1')
// 				mlx_put_image_to_window(mlx, win, pic->wall, i * TILE_SIZE, j * TILE_SIZE);
// 			else if (map[i][j] == 'C')
// 				mlx_put_image_to_window(mlx, win, pic->coin, i * TILE_SIZE, j * TILE_SIZE);
// 			else if (map[i][j] == 'P')
// 				mlx_put_image_to_window(mlx, win, pic->player, i * TILE_SIZE, j * TILE_SIZE);
// 			else if (map[i][j] == 'E')
// 				mlx_put_image_to_window(mlx, win, pic->exit, i * TILE_SIZE, j * TILE_SIZE);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	put_to_place()

// t_assets->wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", width, height);

// mlx_put_image_to_window(mlx, win_ptr, t_assets->wall, x, y);


