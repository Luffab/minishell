/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:52:56 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/25 16:37:22 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*start_len(void)
{
	char	*str;

	str = malloc(1 * sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_substr(char *src, int start, int len)
{
	int		j;
	char	*dst;

	j = 0;
	if (!src)
		return (NULL);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (j < len)
	{
		dst[j] = src[start];
		j++;
		start++;
	}
	dst[j] = 0;
	return (dst);
}
