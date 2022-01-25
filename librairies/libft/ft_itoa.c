/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:23:49 by chilee            #+#    #+#             */
/*   Updated: 2021/12/10 11:14:02 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*dest;
	size_t			len_int;
	unsigned int	num;

	len_int = ft_intlen(n);
	dest = (char *)malloc(sizeof(char) * (len_int + 1));
	if (!dest)
		return (NULL);
	dest[len_int] = '\0';
	if (n == 0)
		dest[0] = '0';
	if (n < 0)
	{
		num = n * (-1);
		dest[0] = '-';
	}
	else
		num = n;
	while (num > 0)
	{
		dest[len_int - 1] = (num % 10) + '0';
		num = (num / 10);
		len_int--;
	}
	return (dest);
}	
