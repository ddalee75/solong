/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:36:15 by chilee            #+#    #+#             */
/*   Updated: 2022/01/17 10:12:49 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int my_key_funct(int keycode, void *param)
{
	printf("key code = %d\n", keycode);
//	mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF);
}

int main(void)
{
	void	*mlx;
	void	*win;
	int x;
	int	y;

	y = 200;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "Hello World");
	while ( y < 600)
	{
		x = 100;
		while (x < 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0x0000FF);
			x++;
		}
		y++;
	}

	y = 200;
	while ( y < 600)
	{
		x = 300;
		while (x < 500)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	
	y = 200;
	while ( y < 600)
	{
		x = 500;
		while (x < 700)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}

	mlx_key_hook (win, my_key_funct, 0);
	mlx_loop(mlx);
}
	
