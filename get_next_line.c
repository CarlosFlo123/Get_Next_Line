/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/21 02:00:52 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list	*get_correct_file(t_list **file, int fd)
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

int				get_next_line(int fd, char **line)
{
	static t_list	*file;
	char			*buffer;
	int				i;
	int				readed;
	t_list			*curr;

	buffer = ft_strnew(BUFF_SIZE + 1);
	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	curr = get_correct_file(&file, fd);
	while ((readed = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[readed] = '\0';
		if (!(curr->content = ft_strjoin(curr->content, buffer)))
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (readed < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = ft_copyuntil(line, curr->content, '\n');
	(i < (int)ft_strlen(curr->content))
		? curr->content += (i + 1)
		: ft_strclr(curr->content);
	return (1);
}
