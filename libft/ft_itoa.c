/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:55:20 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 17:55:05 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long int nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size = 1;
		nbr = nbr * -1;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size + 1);
}

static char	*corps(int tmp, char *str, long int nb)
{
	int	i;
	int	size;

	size = count_size(nb);
	i = size - 1;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (i > 0 && nb >= 10)
	{
		tmp = nb % 10;
		nb = nb / 10;
		str[i--] = tmp + 48;
	}
	if (nb >= 0 && nb < 10)
		str[i] = nb + 48;
	str[size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			tmp;
	char		*str;
	long int	nb;

	tmp = 0;
	nb = n;
	str = NULL;
	str = corps(tmp, str, nb);
	return (str);
}
