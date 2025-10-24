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

// mlx_key_hook(mlx_win, keystroke, info);

// int		mlx_key_hook(t_win_list *win,int (*funct)(),void *param);

// i - 1, j == move up

// i + 1, j == move down

// i, j - 1 == move left

// i , j + 1 == move right

//To check if the destination is valid or not (within borders and a valid target)

// char key_convert(int keycode)
// {
	// 	if (keycode == 13 || keycode == 126)
	// 		return ('u');
	// 	else if (keycode == 1 || keycode == 125)
	// 		return ('d');
	// 	else if (keycode == 0 || keycode == 123)
	// 		return ('l');
	// 	else if (keycode == 2 || keycode == 124)
	// 		return ('r');
	// 	else
	// 		return ('i');
	// }


// int	valid(int i, int j, t_game *info)
// {
// 	if (i >= 0 && i <= info->depth && j >= 0 && j <= info->width)
// 	{
// 		if (info->map[i][j] == 'C' || info->map[i][j] == '0') 
// 			return (0);
// 		else if (info->map[i][j] == 'E')
// 			return (0);
// 		else
// 			return (1);
// 	}
// 	else
// 		return (1);
// }

void	move_up(t_game *info) //, int i, int j)
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
}

void	move_down(t_game *info) //, int i, int j)
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
}

void	move_left(t_game *info) //, int i, int j)
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
}

void	move_right(t_game *info)//, int i, int j)
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
}

int	conditions(int key, t_game *info)
{
	// int	i;
	// int	j;

	// info->i = info->c->start[0];
	// info->j = info->c->start[1];
	mlx_clear_window(info->mlx, info->win);
	if (key == 119)
		move_up(info);//, i--, j);
	else if (key == 115)
		move_down(info);//, i++, j);
	else if (key == 97)
		move_left(info);//, i, j--);
	else if (key == 100)
		move_right(info);//, i, j++);
	init_background(info->mlx, info->win, info->pic, info->map);
	// else
	// 	continue ;
	return (0);
	
	// while (info->c->collectible != 0 && i != info->c->exit[0] && j != info->c->exit[1])
	// {
	// if ((key == 13 || key == 126) && valid(i - 1, j, info) == 0)
	// 	move_up(info, i, j);
	// else if ((key == 1 || key == 125) && valid(i + 1, j, info) == 0)
	// 	move_down(info, i, j);
	// else if ((key == 0 || key == 123) && valid(i, j - 1, info) == 0)
	// 	move_left(info, i, j);
	// else if ((key == 2 || key == 124) && valid(i, j + 1, info) == 0)
	// 	move_right(info, i, j);
	// else
	// 	continue ;
	// }
	//Close window here I guess (Collectibles collected and exit reached after all)
}

//The ones below are keycodes for linux machines presumably
// void	conditions(int key, t_game *info)
// {
// 	int	i;
// 	int	j;

// 	i = info->c->start[0];
// 	j = info->c->start[1];
// 	mlx_clear_window(info->mlx, info->win);
// 	if (key == 13 || key == 126)
// 		move_up(info, i--, j);
// 	else if (key == 1 || key == 125)
// 		move_down(info, i++, j);
// 	else if (key == 0 || key == 123)
// 		move_left(info, i, j--);
// 	else if (key == 2 || key == 124)
// 		move_right(info, i, j++);
// 	init_background(info->mlx, info->win, info->pic, info->map);
// 	// else
// 	// 	continue ;
// 	// return (0);
	
// 	// while (info->c->collectible != 0 && i != info->c->exit[0] && j != info->c->exit[1])
// 	// {
// 	// if ((key == 13 || key == 126) && valid(i - 1, j, info) == 0)
// 	// 	move_up(info, i, j);
// 	// else if ((key == 1 || key == 125) && valid(i + 1, j, info) == 0)
// 	// 	move_down(info, i, j);
// 	// else if ((key == 0 || key == 123) && valid(i, j - 1, info) == 0)
// 	// 	move_left(info, i, j);
// 	// else if ((key == 2 || key == 124) && valid(i, j + 1, info) == 0)
// 	// 	move_right(info, i, j);
// 	// else
// 	// 	continue ;
// 	// }
// 	//Close window here I guess (Collectibles collected and exit reached after all)
// }
	
// void	keystroke(int keycode, t_game *info)
// {
// 	if (keycode == 13 || keycode == 126)
// 	{

// 		ft_prinft("UP (W / UP ARROW)\n");
// 	}
// 	else if (keycode == 1 || keycode == 125)
// 	{
// 		ft_prinft("UP (S / DOWN ARROW)\n");
// 	}
// 	else if (keycode == 0 || keycode == 123)
// 	{
// 		ft_prinft("LEFT (A / LEFT ARROW)\n");
// 	}
// 	else if (keycode == 2 || keycode == 124)
// 	{
// 		ft_prinft("RIGHT (D / RIGHT ARROW)\n");
// 	}
// 	else if (keycode == 53)
// 	{
// 		ft_prinft("ESCAPE\n");
// 	} 
// 	else
// 		ft_printf("Invalid keypress! Please use WASD or up down left right, otherwise press Esc to escape!\n");
// }
