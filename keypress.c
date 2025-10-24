/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 02:44:12 by shaun             #+#    #+#             */
/*   Updated: 2025/10/24 02:44:14 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *info)
{
	char	target;

	target = info->map[info->i - 1][info->j];
	if (target == '0' || target == 'C')
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i - 1][info->j] = 'P';
		info->i--;
		if (target == 'C')
			info->c->collectible--;
	}
	if (target == 'E' && info->c->collectible == 0)
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i--][info->j] = 'P';
		info->i--;
		ft_printf("Congrats gamer, ya beat the game!\n");
		close_shop(info);
	}
}

void	move_down(t_game *info)
{
	char	target;

	target = info->map[info->i + 1][info->j];
	if (target == '0' || target == 'C')
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i + 1][info->j] = 'P';
		info->i++;
		if (target == 'C')
			info->c->collectible--;
	}
	if (target == 'E' && info->c->collectible == 0)
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i + 1][info->j] = 'P';
		info->i++;
		ft_printf("Congrats gamer, ya beat the game!\n");
		close_shop(info);
	}
}

void	move_left(t_game *info)
{
	char	target;

	target = info->map[info->i][info->j - 1];
	if (target == '0' || target == 'C')
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i][info->j - 1] = 'P';
		info->j--;
		if (target == 'C')
			info->c->collectible--;
	}
	if (target == 'E' && info->c->collectible == 0)
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i][info->j - 1] = 'P';
		info->j--;
		ft_printf("Congrats gamer, ya beat the game!\n");
		close_shop(info);
	}
}


void	move_right(t_game *info)
{
	char	target;

	target = info->map[info->i][info->j + 1];
	if (target == '0' || target == 'C')
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i][info->j + 1] = 'P';
		info->j++;
		if (target == 'C')
			info->c->collectible--;
	}
	if (target == 'E' && info->c->collectible == 0)
	{
		info->map[info->i][info->j] = '0';
		info->map[info->i][info->j + 1] = 'P';
		info->j++;
		ft_printf("Congrats gamer, ya beat the game!\n");
		close_shop(info);
	}
}

int	conditions(int key, t_game *info)
{
	mlx_clear_window(info->mlx, info->win);
	if (key == 119)
		move_up(info);
	else if (key == 115)
		move_down(info);
	else if (key == 97)
		move_left(info);
	else if (key == 100)
		move_right(info);
	else if (key == 65307)
		close_shop(info);
	init_backg(info->mlx, info->win, info->pic, info->map);
	return (0);
}
