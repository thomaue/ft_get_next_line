/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:55:06 by tauer             #+#    #+#             */
/*   Updated: 2023/11/28 13:03:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE
# define FT_GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	char			*content;
	struct t_list	*next;
}			t_list;

t_list *ft_lst_get_last(t_list *stash);
int	find_newline(t_list *stash);
void	add_to_stash(t_list **stash, char *buff, int readed);
void	read_and_stash(t_list **stash, int *readed_ptr, int fd);
void	generate_line(char **line, t_list *stash);
char	*get_next_line(int fd);

#endif