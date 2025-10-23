/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:20:05 by shaun             #+#    #+#             */
/*   Updated: 2025/10/20 15:20:07 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parser(char *str)
{
	int	fd;
	int	len;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File %s doesn't exist!\n", str);
		close(fd);
		return (1);
	}
	else
	{
		ft_printf("\nFile %s exists!\n\n", str);
		close(fd);
	}
	len = ft_strlen(str);
	if (len < 5)
	{
		ft_printf("Len of file not possible\n");
		return (1);
	}
	if (ft_strncmp((str + len - 4), ".ber", 5) != 0)
	{
		ft_printf("File does not end in .ber!\n");
		return (1);
	}
	return (0);
}

char	*map_copier(char *str)
{
	size_t	n;
	char	*line;
	char	*grandline;

	n = open(str, O_RDONLY);
	line = get_next_line(n);
	grandline = ft_strdup("");
	grandline = ft_strjoin(grandline, line);
	while (line)
	{
		free(line);
		line = get_next_line(n);
		if (line == NULL)
			break ;
		grandline = ft_strjoin(grandline, line);
	}
	return (grandline);
}

char	**map_translator(char *str)
{
	char	**double_array;

	double_array = ft_split(map_copier(str), '\n');
	return (double_array);
}

int	valid_char(char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
	{
		ft_printf("This is the invalid character: %c\n", c);
		return (1);
	}
	return (0);
}

int	borders(char **map)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(map[i]);
	//Checks if first line in map is purely '1's
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (1);
		j++;
	}
	//Checks if all lines in map are the same length
	while (map[i])
	{
		if (ft_strlen(map[i]) != len || map[i][0] != '1' || map[i][len - 1] != '1')
			return (1);
		i++;
	}
	j = 0;
	//Checks if last line in map is purely '1's
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	map_catalog(char **map, t_catalog *c, t_maze *waze)
{
	int	i;
	int	j;

	i = 0;
	// j = 0;
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
				// c->player++;
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
		ft_printf("Check the count of your items my man, they don't make sense!\n");
		ft_printf("Player: %d, Exit: %d, Collectible/s: %d\n", c->start[2], c->exit[2], c->collectible);
		return (1);
	}
	return (0);
}

int	map_check(char **map, t_catalog *c, t_maze *waze)
{
	c->collectible = 0;
	c->start[2] = 0;
	// c->start[2] = 0;
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
	//Check to see if map is rectangular (all lines the same length?)
	//Can check if the length of every string is the same
	//Can check to see if the first and last string are composed of strictly 1's
	//Can check if every string starts and ends with 1
	//Is the map enclosed in walls (First and last lines & columns should be 1)?

	//Is there something in the map file?


	//Is there only one exit (How many E's on the map)?

	//Is there only one start position (How many P's on the map)?

	//Is there at least one collectible (How many C's on the map)?

	//Can do the following two using flood fill and backtracking algos:
	//1) Is the exit accessible from the start position?
	//2) Are all the collectibles accessible from the start position? 

// size_t	line_count(char *str)
// {
// 	size_t	n;
// 	size_t	line_count;
// 	size_t	index;
// 	char	*line;
// 	char	**double_array;

// 	n = open(str, O_RDONLY);
// 	line_count = 0;
// 	index = 0;
// 	// FILE*	ptr = fopen("multiple_line_no_nl.txt", "r");
// 	// fseek(ptr, 0, SEEK_SET);
// 	line = get_next_line(n);
// 	while (line)
// 	{
// 		printf("Line returned from gnl: %s\n", line);
// 		line_count++;
// 		free(line);
// 		line = get_next_line(n);
// 	}
// 	return (line_count);
// }

// char	**map_copier(char *str, size_t line_count)
// {
// 	size_t	n;
// 	char 	*line;
// 	char	**double_array;

// 	n = open(str, O_RDONLY);
// 	line = 
// 	double_array = malloc(line_count * sizeof(char *));
// 	while (line)
// 	{
// 	}
// }