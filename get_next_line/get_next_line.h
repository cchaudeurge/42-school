/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaudeu <cchaudeu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:17:06 by cchaudeu          #+#    #+#             */
/*   Updated: 2025/08/26 18:49:19 by cchaudeu         ###   ########.fr       */
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
 REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE*/
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

/*TESTING
  REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE*/
int		main(void);
/*get_next_line.c*/
char	*get_next_line(int fd);
int		read_into_stash(int fd, t_list *stash);
int		extract_line(char **line, t_list *stash);
void	extract_surplus(t_list *stash, char *next_line);
int		clean_stash(t_list	**stash);

/*get_next_line_utils.c*/
void	*ft_calloc(size_t nbr, size_t size);
t_list	*ft_lstlast(t_list *lst);
int		found_nl(t_list *stash);
size_t	linelen(t_list *stash);
void	free_lst(t_list **stash);
#endif
