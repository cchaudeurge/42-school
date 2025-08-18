/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:17:06 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/18 21:48:20 by cchaudeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*get_next_line.h*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*for malloc, free*/
# include <stdlib.h>
/*for read*/
# include <unistd.h>
/*TESTING
 * REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE*/
# include <stdio.h>
# include <fcntl.h>  

/*Buffer*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*Linked lists*/
typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

/*Tracker values*/	
typedef struct s_values
{
	int	red;
	int	nl_pos;
	int	fail;
}		t_values;

/*TESTING
 * REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE*/
int		main(void);
/*get_next_line.c*/
char	*get_next_line(int fd);
int		read_into_stash(int fd, t_list **current, t_values *tracker);
char	*extract_surplus(t_list *current, t_values *tracker);
char	*extract(char **line, t_list *stash, t_list *current,
			t_values *tracker);
char	*free_all(t_list	**stashptr, t_list **currentptr, char **line,
			t_values **trackerptr);

/*get_next_line_utils.c*/
int		strln(char *str);
int		lstsi(t_list *stash);
void	free_lst(t_list *stash);
int		has_nl(t_list *current, t_values *tracker);

#endif
