/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:49:37 by chilee            #+#    #+#             */
/*   Updated: 2022/01/25 18:55:21 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_ascii(void)
{
	ft_putendl_fd(KNRM"", 1);
	ft_putendl_fd(KNRM"", 1);
	ft_putendl_fd(KBLU"                  _", 1);
	ft_putendl_fd(KBLU"     ___  ___    | | ___  _ __   __ _ ", 1);
	ft_putendl_fd(KWHT"    / __|/ _ \\   | |/ _ \\| '_ \\ / _` |", 1);
	ft_putendl_fd(KWHT"    \\__ \\ (_) |  | | (_) | | | | (_| |", 1);
	ft_putendl_fd(KRED"    |___/\\___/___|_|\\___/|_| |_|\\__, |", 1);
	ft_putendl_fd(KRED"                                |___/ ", 1);
	ft_putstr(KYEL"        Bonus Bonus Bonus Bonus"KNRM);
	ft_putendl_fd(KNRM"", 1);
}
