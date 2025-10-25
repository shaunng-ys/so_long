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
#define MLX_PUT_IMG mlx_put_image_to_window

//Function for initializing the assets
void	initialize_assets(void	*mlx, t_assets *pic)
{
	int	width;
	int	height;

	pic->exit_str = "assets/scamdew/ladder.xpm";
	pic->wall_str = "assets/scamdew/stone-moss.xpm";
	pic->coin_str = "assets/scamdew/primo.xpm";
	pic->player_str = "assets/scamdew/player-test.xpm";
	pic->back_str = "assets/background/space.xpm";
	pic->exit = mlx_xpm_file_to_image(mlx, pic->exit_str, &width, &height);
	pic->wall = mlx_xpm_file_to_image(mlx, pic->wall_str, &width, &height);
	pic->coin = mlx_xpm_file_to_image(mlx, pic->coin_str, &width, &height);
	pic->player = mlx_xpm_file_to_image(mlx, pic->player_str, &width, &height);
	pic->back = mlx_xpm_file_to_image(mlx, pic->back_str, &width, &height);
}

void	init_backg(void *mlx, void *win, t_assets *pic, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			MLX_PUT_IMG(mlx, win, pic->back, j * TILE, i * TILE);
			if (map[i][j] == '1')
				MLX_PUT_IMG(mlx, win, pic->wall, j * TILE, i * TILE);
			else if (map[i][j] == 'C')
				MLX_PUT_IMG(mlx, win, pic->coin, j * TILE, i * TILE);
			else if (map[i][j] == 'P')
				MLX_PUT_IMG(mlx, win, pic->player, j * TILE, i * TILE);
			else if (map[i][j] == 'E')
				MLX_PUT_IMG(mlx, win, pic->exit, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}
