/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:38:53 by chilee            #+#    #+#             */
/*   Updated: 2021/12/07 11:28:22 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;
	size_t	i;
	char	ch;

	ch = (char)c;
	src = (char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == ch)
			return ((char *)src + i);
		i++;
	}
	return (0);
}
