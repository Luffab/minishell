/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:56:43 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/23 13:18:20 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	i = 0;
	if (!s1 || !s2)
		return (1);
	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (cmp1[i] == cmp2[i] && i < n && cmp1[i] != '\0')
		i++;
	if (i == n)
		i--;
	return (cmp1[i] - cmp2[i]);
}
