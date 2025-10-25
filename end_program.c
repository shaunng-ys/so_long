#include "so_long.h"

int	close_shop(t_game *info)
{
	int	i;

	mlx_destroy_image(info->mlx, info->pic->back);
	mlx_destroy_image(info->mlx, info->pic->wall);
	mlx_destroy_image(info->mlx, info->pic->player);
	mlx_destroy_image(info->mlx, info->pic->exit);
	mlx_destroy_image(info->mlx, info->pic->coin);
	mlx_destroy_window(info->mlx, info->win);
	free(info->pic);
	i = 0;
	free(info->waze);
	while (info->map[i])
		free(info->map[i++]);
	free(info->map);
	free(info);
	exit(EXIT_SUCCESS);
}

void	free_map(char **map, t_game *info, t_maze *waze, t_assets *img)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	free(waze);
	free(info);
	free(img);
	exit(1);
}
