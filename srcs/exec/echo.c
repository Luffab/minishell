/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:18:12 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/11 15:06:15 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_echo(char **str)
{
	int	pos;
	int	n;

	pos = 1;
	n = 0;
	if (str_is_equ(str[pos], "-n"))
	{
		pos++;
		n = 1;
	}
	while (str[pos] != 0)
	{
		while (ft_strcmp(str[pos], "") == 0 && str[pos + 1])
			pos++;
		ft_putstr_fd(str[pos], 1);
		if (str[pos + 1])
			ft_putstr_fd(" ", 1);
		pos++;
	}
	if (n == 0)
		printf("\n");
}
