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
		close(fd);
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
	char	*temp;
	char	*grandline;

	n = open(str, O_RDONLY);
	line = get_next_line(n);
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
	double_array = ft_split(grandline, '\n');
	free(grandline);
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

int	borders(char **map, size_t l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (1);
		j++;
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) != l || map[i][0] != '1' || map[i][l - 1] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}
