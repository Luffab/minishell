/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:23:30 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 18:01:16 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, char charset)
{
	if (c == charset || c == '\0')
		return (1);
	return (0);
}

static int	count(char const *str, char charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if ((is_in_charset(str[i + 1], charset))
			&& (!(is_in_charset(str[i], charset))))
			size++;
		i++;
	}
	return (size);
}

static void	write_res(char *str, char *src, char charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!(is_in_charset(src[i], charset)))
	{
		str[j] = src[i];
		j++;
		i++;
	}
	str[i] = '\0';
}

static char	**malloc_res(char **res, char *str, char charset)
{
	int	i;
	int	j;
	int	ind;

	i = 0;
	ind = 0;
	while (str[i] != '\0')
	{
		if (is_in_charset(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (!(is_in_charset(str[i + j], charset)))
				j++;
			res[ind] = (char *)malloc((j + 1) * sizeof(char));
			write_res(res[ind], str + i, charset);
			i = i + j;
			ind++;
		}
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	res = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	res[count(s, c)] = NULL;
	res = malloc_res(res, str, c);
	return (res);
}
