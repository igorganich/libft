/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:21:34 by iganich           #+#    #+#             */
/*   Updated: 2018/04/20 01:45:37 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *line, char c)
{
	char	*newline;
	int		i;

	i = -1;
	newline = (char*)malloc(ft_strlen(line) + 2);
	while (line[++i])
		newline[i] = line[i];
	newline[i] = c;
	newline[i + 1] = '\0';
	free(line);
	return (newline);
}

int		ft_copying(char **line, char *content, char c)
{
	int i;
	int l;

	i = -1;
	l = 0;
	while (content[++i])
		if (content[i] == c)
			break ;
	free(*line);
	*line = ft_strnew(i);
	while (content[l] && l < i)
	{
		*line = ft_join(*line, content[l]);
		l++;
	}
	return (i);
}
