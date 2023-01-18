/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:41:29 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/09 18:43:38 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*str1;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	str1 = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		str1[i] = s[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
