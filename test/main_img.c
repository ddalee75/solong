/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:21:39 by chilee            #+#    #+#             */
/*   Updated: 2022/01/14 11:55:50 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*relative_path = "./DDA.xpm";
	int		img_width;
	int		img_height;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "Game");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 100, 100);
	mlx_loop(mlx);
}
