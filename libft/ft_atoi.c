/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:55:27 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 17:42:11 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		start;
	int		i;
	long	res;
	int		negative;

	start = 0;
	while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t'
			|| str[start] == '\r' || str[start] == '\n'))
		start++;
	i = start;
	res = 0;
	negative = 0;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9')
			|| (i == start && (str[i] == '-' || str[i] == '+'))))
	{
		if (str[i] == '-')
			negative = 1;
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - 48);
		++i;
	}
	if (negative)
		res *= -1;
	return (res);
}
