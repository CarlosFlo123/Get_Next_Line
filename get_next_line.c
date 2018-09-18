/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/17 23:19:25 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	char	*buffer = 0;
	int		i = 0;
	int		flag = 0;
	char	*tmp = 0;

	line = 0;
	buffer = malloc(sizeof (char *) * BUFF_SIZE + 1);
	tmp = malloc(sizeof (char *) * 80);
	line = malloc(sizeof (char **) * 3);
	*line = malloc(sizeof(char *) * 80);
	while (1)
	{
		//fflush( stdin );
		if (fd < 0 && read(fd, buffer, 0) <= 0)
			return (-1);
		read(fd, buffer, BUFF_SIZE);
		i = 0;
		while (buffer[i])
		{
			//printf("HELLO BITCH");
			if (buffer[i] == '\n' || buffer[i] == '\0')
			{
				tmp = ft_strncpy(tmp, buffer, i);
				//printf("%s\n", tmp);
				*line = ft_strcat(*line, tmp);
				flag = 1;
				if (buffer[i] == '\0')
					return (0);
				break ;
			}
			i++;
		}
		if (flag == 0)
			*line = ft_strcat(*line, buffer);
		if (flag == 1)
			break ;
	}
	printf("%s", *line);
	return (1);
}
