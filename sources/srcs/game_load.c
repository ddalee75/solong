/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:24:52 by chilee            #+#    #+#             */
/*   Updated: 2022/01/24 17:01:15 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
** Map Init making all map char match with their tile images
** Initialises player's position
** Displays Game
*/
void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		img, x * TILESIZE, y * TILESIZE);
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
			else if (game->map[y][x] == 'C')
				put_img(game, game->collectible, x, y);
			else if (game->map[y][x] == 'E')
				put_img(game, game->escape, x, y);
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
	ft_putstr(KGRN"Success\nGame load\n"KNRM);
}
