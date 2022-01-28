/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:56:20 by chilee            #+#    #+#             */
/*   Updated: 2022/01/28 12:00:47 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/*
** count total collectibles
*/
void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->total_collectibles++;
			x++;
		}	
		y++;
	}
}

/*
** Map init making all map char with their tile images
** Initialises player's position
** Display game
*/
void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img,
		x * TILESIZE, y * TILESIZE);
	game->dmove = ft_itoa(game->moves);
	game->botle = ft_itoa(game->collected);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 15, 0x791cf8, "MOVES = ");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 70, 15, 0xFF0000, game->dmove);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 30, 0x791cf8, "BOTTLES =");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 70, 30, 0xFF0000, game->botle);
	free (game->dmove);
	free (game->botle);
}

void	xpm_map_load(t_game *game, int y, int x)
{
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				put_img(game, game->ground, x, y);
			else if (game->map[y][x] == '1')
				put_img(game, game->wall, x, y);
			else if (game->map[y][x] == 'E')
				put_img(game, game->escape, x, y);
			else if (game->map[y][x] == 'C')
				put_img(game, game->collectible, x, y);
			else if (game->map[y][x] == 'P')
			{
				put_img(game, game->p, x, y);
				game->x = x;
				game->y = y;
			}
			x++;
		}
		y++;
	}
}

void	load_game(t_game *game)
{
	game_init(game);
	count_collectibles(game);
	xpm_init(game);
	xpm_map_load(game, 0, 0);
	ft_putstr(KYEL"Success\nGame loaded\n"KNRM);
}
