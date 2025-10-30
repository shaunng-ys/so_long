/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sng <sng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:20:05 by shaun             #+#    #+#             */
/*   Updated: 2025/10/29 22:09:11 by sng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *str)
{
	char	*last_slash;
	int		len;

	len = 0;
	last_slash = ft_strrchr(str, '/');
	if (last_slash == NULL)
		len = ft_strlen(str);
	else
		len = ft_strlen(last_slash + 1);
	if (len < 5)
	{
		ft_printf("Error\nBad extension\n");
		return (1);
	}
	if (ft_strncmp((str + ft_strlen(str) - 4), ".ber", 5) != 0)
	{
		ft_printf("Error\nBad extension \n");
		return (1);
	}
	return (0);
}

int	map_parser(char *str)
{
	int	fd;
	int	len;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile %s doesn't exist!\n", str);
		close(fd);
		return (1);
	}
	else
		close(fd);
	len = ft_strlen(str);
	if (check_extension(str))
		return (1);
	return (0);
}

char	*map_copier(char *str)
{
	size_t	n;
	char	*line;
	char	*temp;
	char	*grandline;

	n = open(str, O_RDONLY);
	line = get_next_line(n);
	if (line == NULL)
		return (free(line), NULL);
	temp = ft_strdup("");
	grandline = ft_strjoin(temp, line);
	free(temp);
	while (line)
	{
		free(line);
		line = get_next_line(n);
		if (line == NULL)
			break ;
		temp = ft_strdup(grandline);
		free(grandline);
		grandline = ft_strjoin(temp, line);
		free(temp);
	}
	free(line);
	return (grandline);
}

char	**map_translator(char *str)
{
	char	*grandline;
	char	**double_array;

	grandline = map_copier(str);
	if (grandline == NULL)
	{
		ft_printf("Error\nEmpty Map\n");
		return (NULL);
	}
	double_array = ft_split(grandline, '\n');
	free(grandline);
	return (double_array);
}

int	borders(char **map, size_t l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (ft_printf("Error\nMaps wall/s uneven/open\n"), 1);
		j++;
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) != l || map[i][0] != '1' || map[i][l - 1] != '1')
			return (ft_printf("Error\nMaps wall/s uneven/open\n"), 1);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (ft_printf("Error\nMaps wall/s uneven/open\n"), 1);
		j++;
	}
	return (0);
}
