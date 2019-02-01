/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:25:09 by iganich           #+#    #+#             */
/*   Updated: 2018/08/19 19:29:12 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimfree(char const *s)
{
	int		i;
	size_t	len;
	char	*str;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		free((char*)s);
		return (ft_strnew(1));
	}
	len = 0;
	while (s[i + len + 1] != '\0')
		len++;
	while (s[len + i] == ' ' || s[len + i] == '\n'
		|| s[len + i] == '\t')
		len--;
	str = ft_strnew(len + 1);
	ret = ft_strncat(str, &(s[i]), len + 1);
	free((char*)s);
	return (ret);
}
