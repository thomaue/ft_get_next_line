/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:26:15 by marvin            #+#    #+#             */
/*   Updated: 2023/11/25 18:26:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// indique la position du linefeed
int	get_line_feed(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// dup jusquau \0 ou \n en lincluant
char	*dup_linefeed(char *str)
{
	char *result;
	size_t size;
	size_t i;

	size = 0;
	i = 0;
	while(str[size] != '\0' && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;	
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	while(size--)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*str;
	char	*result;
	char	*stash_ptr;
	char	*buff_ptr;

	if (stash == NULL || buff == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff)
				+ 1));
	if (!str)
		return (NULL);
	result = str;
	stash_ptr = stash;
	buff_ptr = buff;
	while (*stash_ptr)
		*str++ = *stash_ptr++;
	while (*buff_ptr)
		*str++ = *buff_ptr++;
	*str = '\0';
	//free(stash);
	// free(buff);
	return (result);
}

char	*get_line(int fd, char *stash)
{
	char *readed;
	int checker;

	checker = 0;
	stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stash)
		return (NULL);
	checker = read(fd, stash, BUFFER_SIZE);
	if (checker < 0)
		return (NULL);
	while (get_line_feed(stash) == -1 && checker >= 0)
	{
		readed = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!stash)
			return (NULL);
		checker = read(fd, readed, BUFFER_SIZE);
		if (checker < 0)
			return (NULL);
		stash = ft_strjoin(stash, readed);
		free(readed);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char *temp = NULL;
	char *stash;
	char *buff;

	stash = NULL;
	buff = NULL;
	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (NULL);

	if (temp != NULL)
	{
		if (get_line_feed(temp) >= 0)
		{
			stash = dup_linefeed(temp);
			buff = dup_linefeed(temp + get_line_feed(temp) + 1);
			free(temp);
			temp = dup_linefeed(buff);
			free(buff);
			buff = NULL;
			return (stash);
		}
		else
		{
			buff = dup_linefeed(temp);
			free(temp);
			temp = NULL;
		}
	}
	stash = get_line(fd, stash);
	if (!stash)
		return (NULL);
	if (buff)
		stash = ft_strjoin(buff, stash);
	//free(buff);
	buff = dup_linefeed(stash + get_line_feed(stash) + 1);
	temp = dup_linefeed(buff);
	free(buff);
	buff = NULL;
	stash = dup_linefeed(stash);
	return (stash);
}