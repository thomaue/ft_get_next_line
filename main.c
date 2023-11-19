/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:45 by tauer             #+#    #+#             */
/*   Updated: 2023/11/19 17:23:30 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);

	for (int i = 1; i <= 20; i++)
		printf("%d : %s", i, get_next_line(fd));
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 main.c get_next_line.c
