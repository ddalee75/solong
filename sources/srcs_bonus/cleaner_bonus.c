/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:42:48 by chilee            #+#    #+#             */
/*   Updated: 2022/01/28 11:51:25 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	free_matrix(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_game_noimage(t_game *game)
{
	if (game->ground)
		mlx_destroy_image(game->mlx_ptr, game->ground);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->collectible)
		mlx_destroy_image(game->mlx_ptr, game->collectible);
	if (game->escape)
		mlx_destroy_image(game->mlx_ptr, game->escape);
	if (game->p)
		mlx_destroy_image(game->mlx_ptr, game->p);
	if (game->end_mess)
		mlx_destroy_image(game->mlx_ptr, game->end_mess);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

int	exit_game_error(t_game *game)
{
	free_matrix(game);
	free_game_noimage(game);
	ft_putstr(KYEL"ERROR\n Why did you delete my file?;)\n"KNRM);
	exit (0);
}

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->ground);
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_image(game->mlx_ptr, game->collectible);
	mlx_destroy_image(game->mlx_ptr, game->p);
	mlx_destroy_image(game->mlx_ptr, game->end_mess);
	mlx_destroy_image(game->mlx_ptr, game->escape);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

int	exit_game(t_game *game)
{
	free_matrix(game);
	free_game(game);
	ft_putstr(KBLU"Window closed by user\n"KNRM);
	exit (0);
}
