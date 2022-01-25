/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:39:39 by chilee            #+#    #+#             */
/*   Updated: 2022/01/21 16:41:15 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_init(t_checks *check)
{
	check->p = 0;
	check->e = 0;
	check->c = 0;
}

/*
** Checks File extension
*/
int	check_file_type(char *file)
{
	if (!file || !ft_strchr(file, '.')
		|| (ft_strcmp(ft_strrchr(file, '.'), ".ber") != 0)
		|| (!file[ft_strrchri(file, '.') - 1])
		|| ((ft_strcmp((&file[ft_strchr_gnl(file, '.') - 1]), "/.ber") == 0)))
		return (FILERROR);
	return (0);
}

/*
** Check if only authorized chars are in the map
*/
int	check_chars(char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'P' && map[y][x] != 'E')
				return (CHARERROR);
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Check if walls are valid and Rows are all the same length
*/
int	check_rowsnwalls(char **map)
{
	int		y;
	size_t	x;
	int		right_wall;
	int		last_row;

	y = 0;
	right_wall = ft_strlen(map[y] + 1);
	last_row = 0;
	while (map[last_row])
		last_row++;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[0][x] != '1' || map[y][0] != '1'
				|| map[y][right_wall] != '1' || map[last_row - 1][x] != '1')
				return (WALLERROR);
			x++;
		}
		if (x != ft_strlen(map[0]))
			return (ROWERROR);
		y++;
	}
	return (0);
}

/*
** Check numbers of Players, Exit, Collectible
*/
int	check_counts(char **map, t_checks *check)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				check->p++;
			if (map[y][x] == 'E')
				check->e++;
			if (map[y][x] == 'C')
				check->c++;
			x++;
		}
		y++;
	}
	if (check->p != 1 || check->e != 1 || check->c == 0)
		return (COUNTERROR);
	return (0);
}
