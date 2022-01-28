/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:05:11 by chilee            #+#    #+#             */
/*   Updated: 2022/01/27 16:51:42 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	valid_map(char **map, char *file)
{
	t_checks	check;

	checks_init(&check);
	if (check_file_type(file) == FILERROR)
		return (ft_putstr(KYEL"Error\nInvalid file type, Should be *.ber\n"KNRM));
	else if (check_chars(map) == CHARERROR)
		return (ft_putstr(KYEL"Error\nInvalid set of characters in file\n"KNRM));
	else if (check_rowsnwalls(map) == WALLERROR)
		return (ft_putstr(KYEL"Error\nInvalid wall setting in the map\n"KNRM));
	else if (check_rowsnwalls(map) == ROWERROR)
		return (ft_putstr(KYEL"Error\nInvalid row configuration in file\n"KNRM));
	else if (check_counts(map, &check) == COUNTERROR)
		return (ft_putstr(KYEL"Error\nInvalid P/E/C of empty file\n"KNRM));
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map = create_matrix(av[1]);
		if (!game.map)
			return (ft_putstr(KRED"ERROR\n Invalid Map\n"KNRM));
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
		ft_putstr(KYEL"ERROR\n Please put a <map>.ber as argument\n"KNRM);
	return (0);
}
