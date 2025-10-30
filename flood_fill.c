/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sng <sng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:31:34 by sng               #+#    #+#             */
/*   Updated: 2025/10/30 14:31:37 by sng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_maze *waze, int i, int j)
{
	if (waze->grid[i][j] == '1' || waze->grid[i][j] == 'F')
		return ;
	if (waze->grid[i][j] == 'C')
		waze->collectible--;
	if (waze->grid[i][j] == 'E')
	{
		waze->rescue = 1;
		return ;
	}
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
