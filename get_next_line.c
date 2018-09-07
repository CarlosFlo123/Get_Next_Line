/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/06 17:18:49 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	char	*buffer = 0;
	//int	tmp;
	line = 0;

	buffer = malloc(sizeof (char *) * BUFF_SIZE);
	while (1)
	{
		if (fd < 0 || line == 0 || read(fd, buffer, BUFF_SIZE) <= 0)
			return (-1);
		printf("%s", buffer);
	}
	return (0);
}

int main()
{
	int		fd;
	char	**line; //the pointer that saves the line read from the file descriptor
	line = malloc(sizeof (char **));
	//*line = ft_strnew(18);
	fd = open("sample_file.txt", O_RDONLY);
	//printf("%d", fd);
	if (0 > get_next_line(fd, line))
		printf("Fatal error");
	return (0);
}
