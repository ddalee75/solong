/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:21:51 by chilee            #+#    #+#             */
/*   Updated: 2021/12/06 19:40:17 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*dest;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_is_set(s1[start], set))
		start ++;
	len = ft_strlen(s1);
	if (start == len)
	{
		dest = (char *)malloc(sizeof(char) * (1));
		if (dest == NULL)
			return (NULL);
		ft_memset(dest, '\0', 1);
		return (dest);
	}
	while (ft_is_set(s1[len -1], set))
		len --;
	len = len - start;
	dest = ft_substr(s1, start, len);
	return (dest);
}
