/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/18 16:58:43 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 16:58:43 by marvin           ###   ########.fr       */
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
	free(stash);
	// free(buff);
	return (result);
}

char	*ft_strdup_start(const char *s, size_t pos)
{
	size_t len_s;
	char *str;
	char *ptr;

	len_s = ft_strlen(s);
	if (pos >= len_s)
		return (NULL);
	len_s -= pos;
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (NULL);
	ptr = str;
	s += pos;
	while (*s != '\0')
		*str++ = *s++;
	*str = '\0';
	return (ptr);
}

char	*ft_strdup_linefeed(const char *s)
{
	size_t len_s;
	char *ptr;
	char *str;

	len_s = 0;
	while (s[len_s] != '\0' && s[len_s] != '\n')
		len_s++;
	str = (char *)malloc(sizeof(char) * (len_s + 2));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s != '\0' && *s != '\n')
		*str++ = *s++;
	*str++ = '\n';
	*str = '\0';
	return (ptr);
}

int	is_linefeed(char *buff)
{
	int	size;

	size = 0;
	while (buff[size])
	{
		if (buff[size] == '\n')
			return (size);
		size++;
	}
	return (-1);
}

char	*read_buff(char *buff, int fd)
{
	int ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
		return (NULL);
	buff[ret] = '\0';
	// printf("buff : %s\n", buff);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*stash;
	static char	*remnant = NULL;
	int			index;

	buff = NULL;
	stash = NULL;
	index = 0;
	buff = read_buff(stash, fd);
	while (buff)
	{
		// printf("index : %i | buff : %s\n",index, buff);
		if (!buff)
			break ;
		if (is_linefeed(buff) >= 0)
		{
			stash = ft_strjoin(stash, buff);
			stash = ft_strdup_linefeed(stash);
			if (remnant)
				stash = ft_strjoin(remnant, stash);
			// printf("%s - %d\n", buff, is_linefeed(buff) + 1);
			remnant = ft_strdup_start(buff, is_linefeed(buff) + 1);
			// printf("%s\n", remnant);
			if (!remnant)
				break ;
			if (!stash)
				break ;
			// printf("stash : %s\n", stash);
			break ;
		}
		else
		{
			if (index == 0)
			{
				// printf("%d\n", index);
				stash = ft_strdup_start(buff, 0);
				if (!stash)
					break ;
				// printf("stash : %s\n", stash);
				index++;
			}
			else
			{
				stash = ft_strjoin(stash, buff);
				if (!stash)
					break ;
				// printf("stash : %s\n", stash);
			}
		}
		free(buff);
		buff = read_buff(stash, fd);
	}
	free(buff);

	// printf("static : %s\n", remnant);
	return (stash);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("file.txt", O_RDONLY);

// 	for(int i = 1; i <= 5; i++)
// 		printf("%d : %s", i, get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
