/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:12 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/20 04:31:54 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int		fd;
	char	*line; //the pointer that saves the line read from the file descriptor
	line = malloc(sizeof (char **));
	fd = open("m83.txt", O_RDONLY);
	while (0 != get_next_line(fd, &line))
	{
		printf("%s", line);
		free(line);
	}
	/*for (int i = 0; i < 3 ; i++)
	{
		if (0 < get_next_line(fd, &line))
			printf("%s\nGOOD\n", line);
	}*/
	return (0);
}
