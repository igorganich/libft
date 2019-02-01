/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:06:21 by iganich           #+#    #+#             */
/*   Updated: 2018/04/20 01:47:31 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <stdio.h>

static int		validate(const int fd, char **line, char *buffer)
{
	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	*line = ft_strnew(1);
	if (*line == NULL)
		return (-1);
	return (0);
}

static t_list	*get_fd(t_list **all, int fd)
{
	t_list *current;

	current = *all;
	while (current)
	{
		if ((int)current->content_size == fd)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", fd);
	ft_lstadd(all, current);
	return (*all);
}

int				get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*all;
	int				ints[2];
	t_list			*current;

	if (validate(fd, line, buffer) == -1)
		return (-1);
	current = get_fd(&all, fd);
	while ((ints[1] = (int)read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ints[1]] = '\0';
		if (!(current->content = ft_strjoinfree(current, buffer)))
			return (-1);
		if (ft_strchr(current->content, '\n'))
			break ;
	}
	if (ft_strlen(current->content) == 0 && ints[1] < BUFF_SIZE)
		return (freenode(&all, current) + ft_strdel(line));
	ints[0] = ft_copying(line, current->content, '\n');
	current->content += (ints[0] + 1);
	return (1);
}
