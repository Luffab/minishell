/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luffab <luffab@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:23:19 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/07 13:17:13 by luffab           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char		*ft_strdup_backline(char *s)
{
	char	*str1;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(str1 = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		str1[i] = s[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

static char	*ft_malloc_word(char *s1, char *s2)
{
	char	*str;

	if (!(str = (char *)malloc((ft_strlen(s1) +
		ft_strlen(s2)) * sizeof(char) + 1)))
		return (NULL);
	return (str);
}

char		*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_malloc_word(s1, s2);
	if (s1)
	{
		while (s1[i])
		{
			str[j++] = s1[i];
			i++;
		}
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}