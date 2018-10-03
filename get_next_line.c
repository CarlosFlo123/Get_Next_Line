/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/10/03 00:37:00 by cflores-         ###   ########.fr       */
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
	//tmp = *file;
	return (tmp);
	//return (ft_lstnew(NULL, fd));
}

/*
 *get_index() Where \n is finded
 */
int				get_index(char *ptr)
{
	int		i = 0;
	char	*tmp;
	
	tmp = ptr;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (i);
		i += 1;
	}
	return (i);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*file;
	char			buffer[BUFF_SIZE + 1];
	int				i;
	int				read_bits;
	t_list			*curr;
	char			*tmp;


	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	curr = get_correct_file(&file, fd);
	tmp = NULL;
	while ((read_bits = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_bits] = '\0';
		//tmp = (char *)curr->content;
		tmp = curr->content;
		curr->content = NULL;
		free(curr->content);
		if (!(curr->content = ft_strjoin(tmp, buffer))) //1leak
			return (-1);
		//curr->content = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	
	//while(1);
//	free(tmp);
	if (read_bits < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = ft_copyuntil(line, curr->content, '\n');//4leak
	//i = get_index(curr->content);
	//ft_strncpy(*line, curr->content, i);
	//printf("\n%s", *line);
	//while(1);
	(i < (int)ft_strlen(curr->content))
		? curr->content += (i + 1)
		: ft_strclr(curr->content);
	while (1);
	return (1);
}
