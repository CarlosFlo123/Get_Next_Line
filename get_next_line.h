/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:02:49 by cflores-          #+#    #+#             */
/*   Updated: 2018/09/13 03:13:27 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define EOF = '\0';
# include <fcntl.h>
# include <libft.h>
# define BUFF_SIZE  2

typedef struct	s_line
{
	char		**line;
	int			fd;
}				t_line;

int		get_next_line(const int fd, char **line);

#endif
