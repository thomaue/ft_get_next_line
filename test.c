#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
		stash = ft_strjoin(stash, readed);
		free(readed);
	}
	return (stash);
}

int	main(void)
{
	int	fd;
	char *stash = NULL;
	char *buff = NULL;

	char *result;
	fd = open("file.txt", O_RDONLY);

	result = get_line(fd, stash);
	printf("%s\n", result);

	result = get_line(fd, stash);
	printf("%s\n", result);

	close(fd);
	return (0);
}