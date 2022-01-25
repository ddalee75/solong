/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:30:23 by chilee            #+#    #+#             */
/*   Updated: 2022/01/13 19:21:31 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main(void)
{
	void	*mlx;
//	void 	*mlx_win;
	void	*img;

	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello Body");
	img = mlx_new_image(mlx, 1920, 1080);
//	mlx_loop(mlx);
//}
