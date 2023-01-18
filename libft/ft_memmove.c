/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:39 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 17:59:01 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*before(char *d, char *s, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

static char	*after(char *d, char *s, size_t n)
{
	int	i;

	i = (int)n - 1;
	while (i >= 0)
	{
		d[i] = s[i];
		i--;
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!src && !dest)
		return (NULL);
	if (d < s)
	{
		d = before(d, s, n);
		return (d);
	}
	else
	{
		d = after(d, s, n);
		return (d);
	}
}
