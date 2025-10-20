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
