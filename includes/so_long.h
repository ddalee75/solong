/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:57:26 by chilee            #+#    #+#             */
/*   Updated: 2022/01/24 17:38:32 by chilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** LIBRAIRIES
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "mlx.h"

/*
** Terminal message colors
*/
# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"

/*
** Error Codes
*/
# define WALLERROR	-2
# define CHARERROR	-3
# define COUNTERROR	-4
# define ROWERROR	-5
# define FILERROR	-6

/*
** Tile images pathes
*/
# define GROUND_0 "assets/ground.xpm"
# define WALL_1 "assets/wall.xpm"
# define COLLECTIBLE_C "assets/collectible.xpm"
# define EXIT_E "assets/exit.xpm"
# define PLAYER_W "assets/P_W.xpm"
# define PLAYER_A "assets/P_A.xpm"
# define PLAYER_S "assets/P_S.xpm"
# define PLAYER_D "assets/P_D.xpm"
# define END_MESSAGE "assets/end_mess.xpm"
# define TILESIZE 80 

/*
** Key codes
*/
# define ESC 65307
# define UP_W 119
# define LEFT_A 97
# define DOWN_S 115
# define RIGHT_D 100
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363

/*
** Structures
** All Games's Datas
*/
typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*ground;
	void	*collectible;
	void	*wall;
	void	*escape;
	void	*end_mess;
	void	*p;
	void	*s;
	void	*w;
	void	*d;
	void	*a;
	char	**map;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		window_width;
	int		window_height;
	int		collected;
	int		total_collectibles;
	int		moves;
	int		game_over;
}	t_game;

/*
** Map Check Tool
*/
typedef struct S_check
{
	int	p;
	int	e;
	int	c;
}	t_checks;

/* 
** Ascii 
*/
void	print_ascii(void);

/*
** Map checkers - Util
*/
void	check_init(t_checks *check);
int		check_chars(char **map);
int		check_rowsnwalls(char **map);
int		check_counts(char **map, t_checks *check);
int		check_file_type(char *file);

/*
**Map check and Error -message
*/
int		valid_map(char **map, char *file);

/*
** Game - Initaliation
*/
void	window_size(t_game *game);
void	game_init(t_game *game);
void	count_collectibles(t_game *game);
void	xpm_init(t_game *game);
void	put_img(t_game *game,void *img, int x, int y);
void	xpm_map_load(t_game *game, int y, int x);
void	load_game(t_game *game);

/*
**Map Creation
*/
char	**create_matrix(char *map_av);

/*
**Heap Memory Leaks - management
*/
void	free_matrix(t_game *game);
void	free_game(t_game *game);
int		exit_game(t_game *game);

/*
**Move
*/

void	update_matrixnplayer(t_game *game, void *newplayerimg, int c);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);

/*
**Hooks
*/

int		init_resume_windos(t_game *game);
int		key_hooks(int keycode, t_game *game);
void	inputs(t_game *game);

#endif
