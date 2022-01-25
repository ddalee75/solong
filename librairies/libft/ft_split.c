/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:58:51 by chilee            #+#    #+#             */
/*   Updated: 2021/12/15 14:36:30 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	tab_nb;
	size_t	i;

	i = 0;
	tab_nb = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			tab_nb++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (tab_nb);
}

static char	*ft_cpyword(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	while (j < i)
	{
		cpy[j] = s[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	size_t	place_tab;
	char	**tab;

	place_tab = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			tab[place_tab++] = ft_cpyword(s, c);
			if (!(tab[place_tab - 1]))
			{
				ft_malloc_error(tab);
				return (NULL);
			}
			s = s + ft_strlen(tab[place_tab - 1]);
		}
	}
	tab[place_tab] = NULL;
	return (tab);
}
