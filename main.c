/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:19:40 by cflores-          #+#    #+#             */
/*   Updated: 2018/10/03 02:15:27 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int		fd;
	char	*line; //the pointer that saves the line read from the file descriptor
	//line = malloc(sizeof (char **);
	fd = open("sample_file.txt", O_RDONLY);
	while (0 != get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	/*for (int i = 0; i < 3 ; i++)
	{
		if (0 < get_next_line(fd, &line))
			printf("%s\nGOOD\n", line);
	}*/
	return (0);
}
