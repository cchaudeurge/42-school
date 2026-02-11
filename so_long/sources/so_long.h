/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:07:00 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/10/21 21:38:11 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**so_long.h*/

#ifndef SO_LONG_H
# define SO_LONG_H

/*For exit, malloc, free*/
# include <stdlib.h>
/*For read, write, close*/
# include <unistd.h>
/*For open*/
# include <fcntl.h>\
/*For perror*/
# include <stdio.h>
# include <errno.h>
/*For strerror , size_t*/
# include <string.h>
/*For gettimeofday*/
# include <sys/time.h>
/*For math functions*/
# include <math.h>
/*For key code constants*/
# include <X11/keysym.h>
/*MiniLibX*/
# include "../mlx/mlx.h"
/*libft*/
# include "../libft/libft.h"

/*SPRITES*/
/*PATHS*/
# define PL_UP_BASE		"assets/sprites/player/up_"
# define PL_DOWN_BASE	"assets/sprites/player/down_"
# define PL_LEFT_BASE	"assets/sprites/player/left_"
# define PL_RIGHT_BASE	"assets/sprites/player/right_"
# define COLLECT_BASE	"assets/sprites/coin_"
# define EXIT_BASE		"assets/sprites/exit_"
# define EMPTY_BASE		"assets/sprites/empty_"
# define WALL_BASE		"assets/sprites/wall_"
/*FRAME COUNTS*/
# define PLAYER_FRAMES	4
# define COLLECT_FRAMES	4
# define EXIT_FRAMES	4
# define WALL_FRAMES	2
# define EMPTY_FRAMES	2
/*EXTENSION*/
# define EXTENSION		".xpm"

/*KEYS
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_A		97
# define KEY_W		119
# define KEY_D		100
# define KEY_S		115*/

/*ELEMENTS*/
# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define START			'P'
# define PLAYER			'P'
# define VISITED		'V'

/*GAME OVER STATES*/
# define WON	-1
# define LOST	-2

/*TILE SIZE*/
# define TILE_W	32
# define TILE_H	32

/*STRUCTS*/
typedef struct	s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct	s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}			t_img;

typedef struct	s_player_img
{
	t_img	up[4];
	t_img	down[4];
	t_img	left[4];
	t_img	right[4];
}			t_player_img;

typedef struct	s_env_img
{
	t_img	wall[2];
	t_img	empty[2];
	t_img	exit[4];
}			t_env_img;

typedef struct	s_collect_img
{
	t_img	frame[4];
}				t_collect_img;

typedef struct	s_enemy_img
{
	t_img	frame[4];
}			t_enemy_img;

typedef struct	s_render
{
	void			*mlx;
	void			*win;
	t_player_img	player;
	t_env_img		environment;
	t_collect_img	collectible;
	t_enemy_img		enemy;
	int				frame;
}				t_render;

typedef struct	s_player
{
	t_pos	pos;
	size_t	to_collect;
	size_t	moves;
}				t_player;

/*typedef struct	s_map
{
	char			**array;
	size_t	width;
	size_t	height;
	size_t	collectibles;
	t_pos	start;
	t_pos	exit;
	int				map_conditions[conditions_count];
}				t_map;*/

typedef struct	s_map
{
	char			**array;
	size_t	width;
	size_t	height;
	size_t	collectibles;
	t_pos	start;
	t_pos	exit;
}				t_map;

typedef struct	s_game
{
	t_render	render;
	t_player	player;
	t_map		map;
	int			state;
}				t_game;


/*typedef struct s_checks
{
    t_mapcond   isrectangular;
    t_mapcond   only1exit;
    t_mapcond   only1start;
    t_mapcond   has_collectible;
    t_mapcond   valid_chars;
    t_mapcond   wall_enclosed;
    t_mapcond   valid_path;
}               t_checks;

typedef struct s_mapcond
{
    int     fail;
    char    *errmsg;
    int     (*check_function)(char **);
}               t_mapcond;*/

typedef enum 	e_errtype
{
	sys_err,
	map_err,
	custom_err
}				t_errtype;

typedef enum	e_map_errors
{
	extension,
	characters,
	map_exit,
	start,
	collectibles,
	shape,
	wall_enclosed,
	valid_path,
	conditions_count
}				t_map_errors;

static

/*Linked listXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}               t_list;*/

/*FUNCTIONS*/
/*main.c*/
int	main(int argc, char **argv);
/*init_game.c*/
void	init_game(t_game *game,	char *map_path);
int		key_handler(int keycode, void *param);
void	move_player(t_game *game, t_pos target);
int	exit_game(void *param);
void	render_moves(t_game *game);
void	render_background(t_game *game);
void	render_wall(t_game *game);
int	render_game(void *param);
void	render_won(t_game *game);
/*init_map.c*/
void	*parse_init_check_map(t_game *game, char *map_path);
void	check_extension(t_game *game, char *map_path);
t_list	*create_map_list(int fd, t_game *game);
char	**create_map_array(int fd, t_game *game);
size_t	array_len(char **map);
void	locate_start(t_game *game);
/*check_map1.c*/
void	check_map(t_game *game);
void	check_shape(t_game *game);
void	check_exit(t_game *game);
void	check_start(t_game *game);
size_t	count_element(char **map, char element);
void	check_characters(t_game *game, char *valid_chars);
void	check_wall_enclosed(t_game *game);
void	flood_fill(char **array, int y, int x, t_game *game);
void	check_path(t_game *game);
char	**copy_map_array(t_game *game);
/*exit_and_errors.c*/
void 	puterror(t_errtype errtype, char *context);
void	free_array(char **map);
void	free_img(void *mlx, t_img image);
void	free_all_images(t_game *game);
void	clean_exit(t_game *game, int exit_code, t_errtype errtype, char
*errcontext);
/*init_render_and_player.c*/
void	init_render(t_game *game);
void	init_player(t_game *game);
/*load_images.c*/
char	*build_path(t_game *game, char *base, int frame_num);
void	load_frames(t_game *game, t_img *frames, char *base, int count);
void	load_all_images(t_game *game);

#endif

