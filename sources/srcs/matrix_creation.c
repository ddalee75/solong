/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:44:21 by chilee            #+#    #+#             */
/*   Updated: 2022/01/24 12:45:24 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**create_matrix(char *map_av)
{
	char	**created_matrix;
	char	*buff;
	char	*tmp_buff;
	char	*strmap;
	int		fd;

	fd = open(map_av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	strmap = malloc(sizeof(char) * 1);
	strmap[0] = '\0';
	buff = get_next_line(fd);
	while (buff)
	{
		tmp_buff = strmap;
		strmap = ft_strjoin_gnl(tmp_buff, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	created_matrix = ft_split(strmap, '\n');
	free(strmap);
	close(fd);
	return (created_matrix);
}