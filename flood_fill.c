/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:30:53 by shaun             #+#    #+#             */
/*   Updated: 2025/10/22 15:30:55 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	flood_fill(t_maze *waze, int i, int j)
// {
// 	if (waze->grid[i][j] == '1' || waze->grid[i][j] == 'F')
// 	{
// 		ft_printf("This is the end of the road for this map!01\n");
// 		return ;
// 	}
// 	if (waze->grid[i][j] == 'C')
// 		(waze->collectible)--;
// 	if (waze->grid[i][j] == 'E')
// 	{
// 		ft_printf("Enter here MFer\n");
// 		waze->rescue = 1;
// 	}
// 	waze->grid[i][j] = 'F';
// 	int x = 0;
// 	ft_printf("This is floodfill map!:\n");
// 	while (waze->grid[x])
// 	{
// 		ft_printf("%s\n", waze->grid[x]);
// 		x++;
// 	}
// 	flood_fill(waze, i + 1, j);
// 	flood_fill(waze, i - 1, j);
// 	flood_fill(waze, i, j + 1);
// 	flood_fill(waze, i, j - 1);
// 	if (waze->collectible == 0 && waze->rescue == 1)
// 		waze->result = 0;
// 	else
// 		waze->result = 1;
// }

void	flood_fill(t_maze *waze, int i, int j)
{
	//This is the copy of the map
	//If the current position is out of bounds
	// if (i < 0 || i > waze->width || j < 0 || j > waze->depth)
	// {
	// 	ft_printf("Working is for losers, here's i: %d and j: %d instead, you're welcome!\n", i, j);
	// 	return;
	// }
	//If the current position is not a valid point of entry
	if (waze->grid[i][j] == '1' || waze->grid[i][j] == 'F')
		return ;
	if (waze->grid[i][j] == 'C')
		waze->collectible--;
	if (waze->grid[i][j] == 'E')
		waze->rescue = 1;
	waze->grid[i][j] = 'F';
	flood_fill(waze, i + 1, j);
	flood_fill(waze, i - 1, j);
	flood_fill(waze, i, j + 1);
	flood_fill(waze, i, j - 1);
	if (waze->collectible == 0 && waze->rescue == 1)
		waze->result = 0;
	else
		waze->result = 1;
}