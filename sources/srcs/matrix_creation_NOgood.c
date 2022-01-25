/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:44:21 by chilee            #+#    #+#             */
/*   Updated: 2022/01/24 11:57:14 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**create_matrix(char *map_av)
{
	char	**created_matrix;
	char	*buff;
	int		y;
	int		fd;

	y = 0;
	fd = open(map_av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = get_next_line(fd);
	while (buff)
	{
		created_matrix[y] = buff;
		free(buff);
		y++;
		buff = get_next_line(fd);
	}
	free(buff);
	close(fd);
	return (created_matrix);
}
