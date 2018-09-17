/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:37:12 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/17 05:20:43 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int		fd;
	char	*line; //the pointer that saves the line read from the file descriptor
	line = malloc(sizeof (char **));
	//*line = ft_strnew(18);
	fd = open("sample_file.txt", O_RDONLY);
	//printf("%d", fd);
	//while(get_next_line(fd, &line) == 1)
		//ft_putendl(line);
		//free(line);
	if (0 > get_next_line(fd, &line))
		printf("Fatal error\n");
	return (0);
}