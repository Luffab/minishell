/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:47:41 by fatilly           #+#    #+#             */
/*   Updated: 2021/10/11 17:59:50 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	if (n >= -2147483647 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n / -1;
		}
		if (n < 10)
		{
			ft_putchar_fd(n + '0', fd);
		}
		else
		{
			div = n / 10;
			mod = n % 10;
			ft_putnbr_fd(div, fd);
			ft_putnbr_fd(mod, fd);
		}
	}
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
}
