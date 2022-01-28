/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:57:02 by chilee            #+#    #+#             */
/*   Updated: 2022/01/28 11:57:21 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/*
** Checks wanted destination and updates data according to it
*/
void	update_matrixnplayer(t_game *game)
{
	game->map[game->y][game->x] = '0';
	mlx_destroy_image(game->mlx_ptr, game->p);
	game->moves++;
	count_frames(game);
	animate_player(game);
	game->p = mlx_xpm_file_to_image(game->mlx_ptr, game->img_direction,
			&game->img_width, &game->img_height);
	ft_putstr("\e[1;1H\e[2J");
	print_ascii();
	ft_putstr(KGRN"MOVE = ");
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	printf("Bottle of wine that you drunk : %d/%d\n", game->collected,
		game->total_collectibles);
	ft_putstr(KYEL"Don't drink too much !\nRemaining Liquor(s): ");
	ft_putnbr_fd((game->total_collectibles) - (game->collected), 1);
	ft_putstr("\n");
	if (game->game_over == 1)
	{
		ft_putstr(KYEL"win!\nPress ESC or red cross to close window\n"KNRM);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->end_mess, 80, 80);
		mlx_loop(game->mlx_ptr);
	}
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[y - 1][x] == '0')
	{
		game->map[y - 1][x] = 'P';
		game->direction = 1;
		update_matrixnplayer(game);
	}
	else if (game->map[y -1][x] == 'C')
	{
		game->map[y - 1][x] = 'P';
		game->direction = 1;
		game->collected++;
		update_matrixnplayer(game);
	}
	else if (game->map[y - 1][x] == 'E'
		&& game->collected == game->total_collectibles)
	{
		game->game_over = 1;
		update_matrixnplayer(game);
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[y][x - 1] == '0')
	{
		game->map[y][x - 1] = 'P';
		game->direction = 4;
		update_matrixnplayer(game);
	}
	else if (game->map[y][x - 1] == 'C')
	{
		game->map[y][x - 1] = 'P';
		game->direction = 4;
		game->collected++;
		update_matrixnplayer(game);
	}
	else if (game->map[y][x - 1] == 'E'
		&& game->collected == game->total_collectibles)
	{
		game->game_over = 1;
		update_matrixnplayer(game);
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[y + 1][x] == '0')
	{
		game->map[y + 1][x] = 'P';
		game->direction = 3;
		update_matrixnplayer(game);
	}
	else if (game->map[y +1][x] == 'C')
	{
		game->map[y + 1][x] = 'P';
		game->direction = 3;
		game->collected++;
		update_matrixnplayer(game);
	}
	else if (game->map[y + 1][x] == 'E'
		&& game->collected == game->total_collectibles)
	{
		game->game_over = 1;
		update_matrixnplayer(game);
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[y][x + 1] == '0')
	{
		game->map[y][x + 1] = 'P';
		game->direction = 2;
		update_matrixnplayer(game);
	}
	else if (game->map[y][x + 1] == 'C')
	{
		game->map[y][x + 1] = 'P';
		game->direction = 2;
		game->collected++;
		update_matrixnplayer(game);
	}
	else if (game->map[y][x + 1] == 'E'
		&& game->collected == game->total_collectibles)
	{
		game->game_over = 1;
		update_matrixnplayer(game);
	}
}
