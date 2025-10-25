#include "so_long.h"

int	map_logic(t_maze *waze, t_game *info, char *map_str)
{
	waze->grid = map_translator(map_str);
	waze->collectible = info->coins;
	waze->result = 2;
	waze->rescue = 0;
	flood_fill(waze, waze->i, waze->j);
	if (waze->result == 1)
	{
		ft_printf("Floodfill failed, this map is impossible!\n");
		return (1);
	}
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
