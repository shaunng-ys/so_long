#include "so_long.h"

int	close_shop(t_game *info)
{
	int	i;

	i = 0;
	mlx_destroy_image(info->mlx, info->pic->back);
	mlx_destroy_image(info->mlx, info->pic->wall);
	mlx_destroy_image(info->mlx, info->pic->player);
	mlx_destroy_image(info->mlx, info->pic->exit);
	mlx_destroy_image(info->mlx, info->pic->coin);
	mlx_destroy_window(info->mlx, info->win);
	free(info->pic);
	while (info->waze->grid[i])
		free(info->waze->grid[i++]);
	i = 0;
	free(info->waze->grid);
	free(info->waze);
	while (info->map[i])
		free(info->map[i++]);
	free(info->map);
	free(info);
	exit(EXIT_SUCCESS);
}
