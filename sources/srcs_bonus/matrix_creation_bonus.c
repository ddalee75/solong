/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:22:07 by chilee            #+#    #+#             */
/*   Updated: 2022/01/31 12:18:36 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	double_newline(char *s)
{
	while (*s)
	{
		if (*s == '\n' && *(s + 1))
		{
			s++;
			if (*s != '\n')
				s++;
			else
				return (1);
		}
		if (*s != '\0')
			s++;
	}
	return (0);
}

char	**my_exit(int fd, char *str)
{
	close(fd);
	free(str);
	ft_putstr(KGRN"Error\nOnly 1 newline allowed before the end of map"KNRM);
	exit (0);
}

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
	strmap = malloc(sizeof(char));
	strmap[0] = '\0';
	buff = get_next_line(fd);
	while (buff)
	{
		tmp_buff = strmap;
		strmap = ft_strjoin_gnl(tmp_buff, buff);
		free (buff);
		buff = get_next_line(fd);
	}
	if (double_newline(strmap))
		return (my_exit(fd, strmap));
	created_matrix = ft_split(strmap, '\n');
	free (strmap);
	return (created_matrix);
}
