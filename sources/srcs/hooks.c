/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:10:03 by chilee            #+#    #+#             */
/*   Updated: 2022/01/18 17:02:26 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	init_resume_window(t_game *game)
{
	xpm_map_load(game, 0, 0);
	return (0);
}

int	key_hooks(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		exit_game(game);
	}
	if (!game->game_over)
	{
		if (keycode == UP_W || keycode == ARROW_UP)
			move_up(game);
		else if (keycode == LEFT_A || keycode == ARROW_LEFT)
			move_left(game);
		else if (keycode == RIGHT_D || keycode == ARROW_RIGHT)
			move_right(game);
		else if (keycode == DOWN_S || keycode == ARROW_DOWN)
			move_down(game);
	}
	xpm_map_load(game, 0, 0);
	return (0);
}

/*
** Manages Keyboard and Mouse inputs
** Red Cross colose, keypress, minimise window)
*/
void	inputs(t_game *game)
{
	mlx_hook(game->mlx_win, 33, 1L << 5, &exit_game, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_hooks, game);
	mlx_hook(game->mlx_win, 9, 1L << 21, &init_resume_window, game);
}	
