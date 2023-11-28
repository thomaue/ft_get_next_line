/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:45 by tauer             #+#    #+#             */
/*   Updated: 2023/11/28 11:36:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *line;
	
	fd = open("file.txt", O_RDONLY);

	for(int i = 1; i <= 20; i++)
	{
		line = get_next_line(fd);
		printf("%d - %s",i, line);
		free(line);
	}
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 main.c get_next_line.c
