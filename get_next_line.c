/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/10/04 00:52:58 by cflores-         ###   ########.fr       */
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
	return (tmp);
}

/*void			update_content(int read_bits, char *content)
{
	char *tmp = NULL;

	if (read_bits < (int)ft_strlen(content))
	{
		tmp = ft_strdup(content + (read_bits + 1));
		ft_strdel(&content);
		content = tmp;
	}
	else
		ft_strclr(content);
	if (tmp)
		ft_strdel(&tmp);
}*/

int				get_next_line(int fd, char **line)
{
	static t_list	*file;
	char			buffer[BUFF_SIZE + 1];
	int				read_bits;
	t_list			*curr;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	curr = get_correct_file(&file, fd);
	while ((read_bits = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_bits] = '\0';
		tmp = curr->content;
		if (!(curr->content = ft_strjoin(tmp, buffer)))
			return (-1);
		ft_strdel(&tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bits < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	read_bits = ft_copyuntil(line, curr->content, '\n');
	if (read_bits < (int)ft_strlen(curr->content))
	{
		tmp = ft_strdup(curr->content + (read_bits + 1));
		ft_strdel(&curr->content);
		curr->content = tmp;
	}
	else
		ft_strclr(curr->content);
	return (1);
}
