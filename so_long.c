/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sng <sng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:29:50 by shaun             #+#    #+#             */
/*   Updated: 2025/10/29 22:18:39 by sng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *info, t_assets *image, t_maze *waze, char **map)
{
	info->moves = 0;
	initialize_assets(info->mlx, image);
	init_backg(info->mlx, info->win, image, map);
	g_init(info, image, waze, map);
}

void	init_mlx(t_game *info, t_maze *waze)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx,
			(waze->width + 1) * TILE, (waze->depth + 1) * TILE, "Game");
}

int	main(int argc, char **argv)
{
	char		**map;
	t_maze		*waze;
	t_assets	*image;
	t_game		*info;

	if (argc > 2)
		return (ft_printf("Error\nWrong number of arguments\n"), 1);
	if (map_parser(argv[1]) != 0)
		return (1);
	info = malloc(sizeof(t_game));
	waze = malloc(sizeof(t_maze));
	image = malloc(sizeof(t_assets));
	map = map_translator(argv[1]);
	if (map == NULL)
		return (free(info), free(waze), free(image), 1);
	if (map_check(map, info, waze) == 1)
		free_map(map, info, waze, image);
	if (map_logic(waze, info, argv[1]) == 1)
		free_map(map, info, waze, image);
	init_mlx(info, waze);
	init(info, image, waze, map);
	mlx_key_hook(info->win, conditions, info);
	mlx_hook(info->win, 17, 0, &close_shop, info);
	mlx_loop(info->mlx);
	return (0);
}
