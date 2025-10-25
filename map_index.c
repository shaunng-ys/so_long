/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:45:26 by shaun             #+#    #+#             */
/*   Updated: 2025/10/25 18:45:30 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_to_catalog(t_game *info, char **map, int i, int j)
{
	if (valid_char(map[i][j]) == 1)
		return (1);
	if (map[i][j] == 'C')
		info->coins++;
	if (map[i][j] == 'P')
	{
		info->waze->i = i;
		info->waze->j = j;
		info->start[0] = i;
		info->start[1] = j;
		info->start[2]++;
	}
	if (map[i][j] == 'E')
	{
		info->exit[0] = i;
		info->exit[1] = j;
		info->exit[2]++;
	}
	return (0);
}

int	map_catalog(char **map, t_game *info, t_maze *waze)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->waze = waze;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (add_to_catalog(info, map, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	waze->depth = i - 1;
	waze->width = j - 1;
	if (info->start[2] != 1 || info->exit[2] != 1 || info->coins < 1)
	{
		ft_printf("Error\nInvalid map, check your item count against rules!\n");
		return (1);
	}
	return (0);
}

int	map_check(char **map, t_game *info, t_maze *waze)
{
	size_t	len;

	info->coins = 0;
	info->start[2] = 0;
	info->exit[2] = 0;
	len = ft_strlen(map[0]);
	if (borders(map, len) != 0)
		return (1);
	if (map_catalog(map, info, waze) != 0)
		return (1);
	return (0);
}

void	map_display(char **map, t_game *info, t_maze *waze)
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
	ft_printf("Collectible/s: %d\n", info->coins);
	ft_printf("Player/s: %d\nExit/s: %d\n", info->start[2], info->exit[2]);
	ft_printf("Width: %d\nDepth: %d\n", waze->width, waze->depth);
}
