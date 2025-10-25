/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:45:43 by shaun             #+#    #+#             */
/*   Updated: 2025/10/25 18:45:46 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_logic(t_maze *waze, t_game *info, char *map_str)
{
	int	i;

	waze->grid = map_translator(map_str);
	waze->collectible = info->coins;
	waze->result = 2;
	waze->rescue = 0;
	flood_fill(waze, waze->i, waze->j);
	if (waze->result == 1)
	{
		i = 0;
		while (waze->grid[i])
			free(waze->grid[i++]);
		free(waze->grid);
		ft_printf("Error\nFloodfill failed, this map is impossible\n");
		return (1);
	}
	i = 0;
	while (waze->grid[i])
		free(waze->grid[i++]);
	free(waze->grid);
	return (0);
}

void	g_init(t_game *info, t_assets *img, t_maze *waze, char **map)
{
	info->map = map;
	info->pic = img;
	info->waze = waze;
	info->i = info->start[0];
	info->j = info->start[1];
}
