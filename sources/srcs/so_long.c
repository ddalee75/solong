/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:32:03 by chilee            #+#    #+#             */
/*   Updated: 2022/01/31 11:28:57 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	valid_map(char **map, char *file)
{
	t_checks	check;

	check_init(&check);
	if (check_file_type(file) == FILERROR)
		return (ft_putstr(KYEL"Error\nInvalid file type, Should be *.ber\n"KNRM));
	else if (check_chars(map) == CHARERROR)
		return (ft_putstr(KYEL"Error\nInvalid characters(only for 10PEC)\n"KNRM));
	else if (check_rowsnwalls(map) == WALLERROR)
		return (ft_putstr(KYEL"Error\nInvalid wall setting\n"KNRM));
	else if (check_rowsnwalls(map) == ROWERROR)
		return (ft_putstr(KYEL"Error\nInvalid row setting\n"KNRM));
	else if (check_counts(map, &check) == COUNTERROR)
		return (ft_putstr(KYEL"Error\nInvalid P/E/C or empty file \n"KNRM));
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map = create_matrix(av[1]);
		if (!game.map)
			return (ft_putstr(KRED"Error\nInvalid map\n"KNRM));
		if (!valid_map(game.map, av[1]))
		{
			print_ascii();
			load_game(&game);
			inputs(&game);
			mlx_loop(game.mlx_ptr);
		}
		else
			free_matrix(&game);
	}
	else
		ft_putstr(KYEL"Error\nPlease put a <map>.ber as arugment\n"KNRM);
	return (0);
}
