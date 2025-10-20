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
		ft_printf("File %s exists!\n", str);
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
	ft_printf("This is the grandline: %s\n", grandline);
	while (line)
	{
		printf("Line returned from gnl: %s\n", line);
		free(line);
		line = get_next_line(n);
		grandline = ft_strjoin(grandline, line);
		ft_printf("This is the grandline: %s\n", grandline);
	}
	printf("This is the grandline: %s!\n", grandline);
	return (grandline);
}

char	**map_translator(char *str)
{
	char	**double_array;

	double_array = ft_split(map_copier(str), '\n');
	return (double_array);
}

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