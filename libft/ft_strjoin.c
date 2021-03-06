/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:12:09 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/14 13:50:01 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*malloc_word(const char *s1, const char *s2)
{
	char *str;

	if (!(str = (char *)malloc((ft_strlen(s1) +
		ft_strlen(s2)) * sizeof(char) + 1)))
		return (NULL);
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc_word(s1, s2);
	if (s1)
	{
		while (s1[i])
		{
			str[j] = s1[i];
			i++;
			j++;
		}
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
