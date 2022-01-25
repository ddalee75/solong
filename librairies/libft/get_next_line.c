/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:11:31 by chilee            #+#    #+#             */
/*   Updated: 2022/01/20 16:35:16 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 50

char	*ft_find_n(char *tmp, int fd)
{
	char	*buf;
	int		v_ret;

	v_ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (v_ret != 0 && !ft_strchr_gnl(tmp, '\n'))
	{
		v_ret = read(fd, buf, BUFFER_SIZE);
		if (v_ret == -1)
		{
			free(buf);
			return (NULL);
		}				
		buf[v_ret] = '\0';
		tmp = ft_strjoin_gnl(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*ft_get_bf_n(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_get_af_n(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}	
	tmp = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (str[i + j])
	{
		tmp[j] = str [i + j];
		j++;
	}
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_find_n(tmp, fd);
	if (!tmp)
		return (NULL);
	if (!tmp[0])
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line = ft_get_bf_n(tmp);
	tmp = ft_get_af_n(tmp);
	return (line);
}
