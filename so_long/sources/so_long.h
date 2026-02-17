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
/*For boolean*/
# include <stdbool.h>
/*MiniLibX*/
# include "../minilibx-linux/mlx.h"
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
/*TILE SIZE*/
# define TILE_W	64
# define TILE_H	64

/*ELEMENTS*/
# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define START			'P'
# define VISITED		'V'
# define VALID_CHARSET	"01CEP"	

/*ENUMS*/
typedef enum	e_game_state
{
	playing,
	won
}				t_game_state;

typedef enum 	e_direction
{
	down,
	up,
	left,
	right
}				t_direction;

typedef enum 	e_errtype
{
	sys_err,
	map_err,
	custom_err,
	no_error
}				t_errtype;

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
	t_img	coll[4];
}			t_env_img;

typedef struct	s_anim_frames
{
	int	exit;
	int	coll;
	int	player;
}				t_anim_frames;

typedef struct	s_render
{
	void			*mlx;
	void			*win;
	t_player_img	player;
	t_env_img		env;
	t_anim_frames	anim;
	int				anim_counter;
	bool			needed;
}				t_render;

typedef struct	s_player
{
	t_pos	pos;
	int		direction;
	size_t	moves;
}				t_player;

typedef struct	s_map
{
	char	**array;
	int		width;
	int		height;
	size_t	collectibles;
	bool	exit_is_open;
}				t_map;

typedef struct	s_game
{
	t_render		render;
	t_player		player;
	t_map			map;
	t_game_state	state;
}				t_game;

/*FUNCTIONS*/
/*game_init_and_controls.c*/
void	init_game(t_game *game, char *map_path);
int		key_handler(int keycode, void *param);
void	move_player(t_game *game, int dx, int dy, t_direction direction);
void	put_moves(t_game *game);
int		exit_game(void *param);
/*game_loop.c*/
int		game_loop(void *param);
void	update_animation_frames(t_game *game);
void	render_game(t_game *game);
/*game_render.c*/
void	render_environment(t_game *game);
void	render_non_empty_env_tile(t_game *game, int x, int y);
void	render_player(t_game *game);
void	render_moves(t_game *game);
/*map_parse.c*/
void	parse_init_check_map(t_game *game, char *map_path);
char	**create_map_array(int fd, t_game *game);
t_list	*create_map_list(int fd, t_game *game);
int		array_len(char **map);
void	locate_start(t_game *game);
/*map_validate_1.c*/
void	check_map(t_game *game);
void	check_characters(t_game *game, char *valid_chars);
void	check_shape(t_game *game);
void	check_exit_and_start(t_game *game);
size_t	count_element(char **map, char element);
/*map_validate_2.c*/
void	check_wall_enclosed(t_game *game);
void	flood_fill(char **array, int y, int x, t_game *game);
void	check_path(t_game *game);
char	**copy_map_array(t_game *game);
void	check_extension(t_game *game, char *map_path);
/*errors_and_exit.c*/
void 	puterror(t_errtype errtype, char *context);
void	free_array(char **map);
void	free_img(void *mlx, t_img image);
void	free_all_images(t_game *game);
void	clean_exit(t_game *game, int exit_code, t_errtype errtype, char
*errcontext);
/*images_load.c*/
char	*build_path(t_game *game, char *base, int frame_num);
void	load_frames(t_game *game, t_img *frames, char *base, int count);
void	load_all_images(t_game *game);

#endif

