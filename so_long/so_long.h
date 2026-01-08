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

/
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

/*KEYS*/
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_A		97
# define KEY_W		119
# define KEY_D		100
# define KEY_S		115

/*ELEMENTS*/
# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define START			'P'

/*STRUCTS*/
typedef struct	s_game
{
	const t_render	*render;
	const t_player	*player;
	const t_map		*map;
}				t_game;

typedef struct	s_render
{
	const void	*mlx;
	const void	*win;
}				t_render;

typedef struct	s_player
{
	size_t	x;
	size_t	y;
	size_t	collected;
	size_t	moves;
}				t_player;

typedef struct	s_map
{
	char			**array;
	const size_t	width;
	const size_t	height;
	const size_t	collectibles;
	const size_t	start_y;
	const size_t	start_x;
	int				map_conditions[conditions_count];
}				t_map;

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
	system_error;
	map_error;
	custom_error;
}				t_errtype;

typedef enum	e_map_errors
{
	extension;
	characters;
	exit;
	start;
	collectibles;
	shape;
	wall_enclosed;
	valid_path;
	conditions_count;
}				t_map_errors;

static

/*Linked listXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}               t_list;

#endif

