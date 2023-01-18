/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:59:28 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 18:06:40 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				ind;
	char			*str;

	i = 0;
	ind = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	while (ind < ft_strlen(s))
	{
		str[ind] = f(i, s[ind]);
		ind++;
		i++;
	}
	str[ind] = '\0';
	return (str);
}
