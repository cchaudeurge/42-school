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

/*so_long.h*/

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
/*For strerror*/
# include <string.h>
/*For gettimeofday*/
# include <sys/time.h>
/*For math functions*/
# include <math.h>

typedef struct s_checks
{
    t_mapcond   isrectangular;
    t_mapcond   only1exit;
    t_mapcond   only1start;
    t_mapcond   has_collectible;
    t_mapcond   valid_chars;
    t_mapcond   wall_enclosed;
    t_mapcond   valid_path;
}               t_checks;

typedef struct  s_mapcond
{
    int     fail;
    char    *errmsg;
    int     (*check_function)(char **);
}               t_mapcond;

/*Linked listXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}               t_list;

#endif

