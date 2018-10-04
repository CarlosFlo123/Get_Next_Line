/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:53 by cflores-          #+#    #+#             */
/*   Updated: 2018/10/03 23:20:38 by cflores-         ###   ########.fr       */
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
	//curr->content = NULL;
	while ((read_bits = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_bits] = '\0';
		tmp = curr->content;
		//ft_strdel(&curr->content);
		//free((void *)curr->content);
		//curr->content = NULL;
		//free(curr->content);
		if (!(curr->content = ft_strjoin(tmp, buffer))) //1leaki
			return (-1);
		ft_strdel(&tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	/* end of file
	if (read_bits == 0)	
		return (0);
		*/
	//while(1);
	if (read_bits < BUFF_SIZE && !ft_strlen(curr->content))
	{
		//ft_strdel(&curr-content);
		//free(curr);
		return (0);
	}
	i = ft_copyuntil(line, curr->content, '\n');//4leak
	//i = ge
	//t_index(curr->content);
	//ft_strncpy(*line, curr->content, i);
	//
	//printf("\n%s", *line);
//	while(1);
//	curr->content[i+1]
	if (i < (int) ft_strlen(curr->content))
	{
		tmp = ft_strdup(curr->content + (i + 1));
		ft_strdel(&curr->content);
		curr->content = tmp;
	}
	else
		ft_strclr(curr->content);
	/*
	(i< (int)ft_strlen(curr->content))
		? curr->content += (i + 1)
		: ft_strclr(curr->content);
	*/
	//while (1);
	return (1);
}
