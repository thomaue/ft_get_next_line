/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:45 by tauer             #+#    #+#             */
/*   Updated: 2023/11/27 23:58:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *line;
	
	fd = open("file.txt", O_RDONLY);

	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 main.c get_next_line.c
