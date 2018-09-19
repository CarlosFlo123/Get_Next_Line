/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/18 23:23:11 by cflores-         ###   ########.fr       */
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
	int		readed = 0;
	//t_list	*curr;

	buffer = ft_strnew(BUFF_SIZE);
	//line = 0;
	//tmp = malloc(sizeof (char *) * 80);
	//line = malloc(sizeof (char **) * 3);
	//*line = malloc(sizeof(char *) * 80);
	while (1)
	{
		//fflush( stdin );
		//if (!(buffer = ft_strnew(BUFF_SIZE)))
		//	return (-1);
		if (fd < 0 && read(fd, buffer, 0) <= 0)
			return (-1);
		readed = read(fd, buffer, BUFF_SIZE);
		i = 0;
		while (buffer[i])
		{
			tmp = ft_strnew(1);
			//printf("HELLO BITCH");
			if (buffer[i] == '\n')
			{
				tmp = ft_strncpy(tmp, buffer, i);
				//printf("%s\n", tmp);
				*line = ft_strjoin(*line, tmp);
				flag = 1;
				free(tmp);
				break ;
			}
			i++;
		}
		if (readed == 0)
		{
			printf("END OF FILE");
			//free(buffer);
			return (0);
		}
		if (flag == 0)
		{
			*line = ft_strjoin(*line, buffer);
			//free(buffer);
		}
		if (flag == 1)
		{
			//free(buffer);
			break ;
		}
	}
	//printf("%s", *line);
	return (1);
}
