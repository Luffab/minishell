/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:22:38 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 18:11:37 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*suppr_before(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	s = ft_strdup(str + i + 1);
	free(str);
	return (s);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	char		buf[BUFFER_SIZE + 1];

	ret = BUFFER_SIZE;
	if (BUFFER_SIZE < 1 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while (!(ft_strchr(str, '\n')) && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		str = ft_strjoinn(str, buf);
	}
	*line = ft_strdup_backline(str);
	if (ret < BUFFER_SIZE && !(ft_strchr(str, '\n')))
	{
		free(str);
		str = NULL;
		return (0);
	}
	str = suppr_before(str);
	return (1);
}
