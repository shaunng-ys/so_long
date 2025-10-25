/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:29:50 by shaun             #+#    #+#             */
/*   Updated: 2025/10/22 15:29:53 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *info, t_assets *image, t_maze *waze, char **map)
{
	initialize_assets(info->mlx, image);
	init_backg(info->mlx, info->win, image, map);
	g_init(info, image, waze, map);
}

int	main(int argc, char **argv)
{
	char		**map;
	t_maze		*waze;
	t_assets	*image;
	t_game		*info;

	if (argc != 2)
		return (1);
	info = malloc(sizeof(t_game));
	waze = malloc(sizeof(t_maze));
	image = malloc(sizeof(t_assets));
	info->mlx = mlx_init();
	if (map_parser(argv[1]) != 0)
		return (1);
	map = map_translator(argv[1]);
	if (map_check(map, info, waze) == 1)
		return (1);
	if (map_logic(waze, info, argv[1]) == 1)
		return (1);
	info->win = mlx_new_window(info->mlx,
			(waze->width + 1) * TILE, (waze->depth + 1) * TILE, "Game");
	init(info, image, waze, map);
	mlx_key_hook(info->win, conditions, info);
	mlx_hook(info->win, 17, 0, &close_shop, info);
	mlx_loop(info->mlx);
	return (0);
}
