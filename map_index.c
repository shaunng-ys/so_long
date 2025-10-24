

#include "so_long.h"

int	map_catalog(char **map, t_catalog *c, t_maze *waze)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (valid_char(map[i][j]) == 1)
				return (1);
			if (map[i][j] == 'C')
				c->collectible++;
			if (map[i][j] == 'P')
			{
				waze->i = i;
				waze->j = j;
				c->start[0] = i;
				c->start[1] = j;
				c->start[2]++;
			}
			if (map[i][j] == 'E')
			{
				c->exit[0] = i;
				c->exit[1] = j;
				c->exit[2]++;
			}
			j++;
		}
		i++;
	}
	waze->depth = i - 1;
	waze->width = j - 1;
	if (c->start[2] != 1 || c->exit[2] != 1 || c->collectible < 1)
	{
		ft_printf("Item count invalid: Player: %d, Exit: %d, Collectible/s: %d\n", c->start[2], c->exit[2], c->collectible);
		return (1);
	}
	return (0);
}

int	map_check(char **map, t_catalog *c, t_maze *waze)
{
	c->collectible = 0;
	c->start[2] = 0;
	c->exit[2] = 0;
	if (borders(map) != 0)
		return (1);
	if (map_catalog(map, c, waze) != 0)
		return (1);
	return (0);
}

void	map_display(char **map, t_catalog *c, t_maze *waze)
{
	int	i;

	i = 0;
	ft_printf("This is le map!:\n");
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("\nMap Info:\n");
	ft_printf("Collectible/s: %d\n", c->collectible);
	ft_printf("Player/s: %d\nExit/s: %d\n", c->start[2], c->exit[2]);
	ft_printf("Width: %d\nDepth: %d\n", waze->width, waze->depth);

}
