/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/20 04:38:04 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list			*get_correct_file(t_list **file, int fd)
{
	t_list				*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}



int		get_next_line(int fd, char **line)
{
	static t_list	*file;
	char			*buffer = 0;
	int				i = 0;
	int				flag = 0;
	char			*tmp = 0;
	int				readed = 0;
	t_list			*curr;
	
	buffer = ft_strnew(BUFF_SIZE);
	while (1)
	{
		if (fd < 0 && read(fd, buffer, 0) <= 0)
			return (-1);
		curr = get_correct_file(&file, fd);
		readed = read(fd, buffer, BUFF_SIZE);
		i = 0;
		while (buffer[i])
		{
			tmp = ft_strnew(1);
			if (buffer[i] == '\n')
			{
				flag = 1;
				break ;
			}
			i++;
		}
		*line = curr->content;
		if (readed == 0)
			return (0);
		if (flag == 0)
			curr->content = ft_strjoin(curr->content, buffer);
		if (flag == 1)
		{
			curr->content = buffer;
			break ;
		}
	}
	return (1);
}
