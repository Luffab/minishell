/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:36:10 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/25 16:32:45 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substrr(char *src, int start, int len)
{
	int		j;
	char	*dst;

	j = 0;
	if (!src)
		return (NULL);
	dst = malloc((len + 1) * sizeof(char));
	while (j < len)
	{
		dst[j] = src[start];
		j++;
		start++;
	}
	dst[j] = 0;
	if (src)
		free(src);
	return (dst);
}

char	*malloc_worddd(char *s1, char *s2)
{
	char	*str;

	str = (char *)malloc((ft_strlen(s1)
				+ ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoind(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc_worddd(s1, s2);
	if (s1)
	{
		while (s1[i])
		{
			str[j] = s1[i];
			i++;
			j++;
		}
		free(s1);
	}
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoindd(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	str = malloc_worddd(s1, s2);
	if (s1)
	{
		while (s1[++i])
		{
			str[j] = s1[i];
			j++;
		}
		free(s1);
	}
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	free(s2);
	str[j] = '\0';
	return (str);
}
