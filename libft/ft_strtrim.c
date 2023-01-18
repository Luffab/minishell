/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:38:23 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 18:07:34 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*deb_fin(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	*str = '\0';
	return (str);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	deb;
	size_t	fin;
	int		ind;
	char	*str;

	if (!s1)
		return (NULL);
	deb = 0;
	fin = ft_strlen(s1) - 1;
	ind = 0;
	while (is_in_set(s1[deb], set))
		deb++;
	if (deb == fin + 1)
		return (str = deb_fin());
	while (is_in_set(s1[fin], set))
		fin--;
	str = (char *)malloc((fin - deb + 2) * sizeof(char));
	while (deb <= fin)
	{
		str[ind++] = s1[deb];
		deb++;
	}
	str[ind] = '\0';
	return (str);
}
