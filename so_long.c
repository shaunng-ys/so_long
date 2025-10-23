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



int	main(int argc, char **argv)
{
	char		**map;
	t_catalog	*c;
	t_maze		*waze;
	t_assets	*image;
	void		*mlx;
	void		*mlx_win;
	// void		*img;
	
	mlx = mlx_init();
	c = malloc(sizeof(t_catalog));
	waze = malloc(sizeof(t_maze));
	image = malloc(sizeof(t_assets));
	if (argc != 2)
		return (1);
	else
	{
		//map_parser checks the user input for a valid map file (format)
		if (map_parser(argv[1]) != 0)
			return (1);
		//map_translator gets a copy of the map given by the user
		map = map_translator(argv[1]);
		//map_check checks the map for its elements and if its conforms
		//with the rules i.e. no more than 1 player, exit etc.
		if (map_check(map, c, waze) == 1)
			return (1);
		//map_display displays the map in character form and prints
		//the number of each element
		map_display(map, c, waze);
		waze->grid = map_translator(argv[1]);
		waze->collectible = c->collectible;
		waze->result = 2;
		// waze->i 
		// if(flood_fill(waze, waze->i, waze->j == 1))
		waze->rescue = 0;
		// ft_printf("i: %d, j: %d\n", waze->i, waze->j);
		flood_fill(waze, waze->i, waze->j);
		ft_printf("Collectibles: %d, Exit Result: %d\n", waze->collectible, waze->rescue);
		if (waze->result == 1)
		{
			ft_printf("Floodfill failed, this map is impossible!\n");
			return (1);
		}
		map_display(waze->grid, c, waze);
		if (mlx == NULL)
			return (printf("error\n"), 1);
		mlx_win = mlx_new_window(mlx, waze->width * TILE_SIZE, waze->depth * TILE_SIZE, "Screw you, I don't play your games");
		initialize_assets(mlx, image);
		init_background(mlx, mlx_win, image, map);
		mlx_loop(mlx);
		return (0);
	}
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;

// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 		return (printf("error\n"), 1);
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Screw you, I don't play your games");
// 	mlx_loop(mlx);
// 	return (0);
// }
