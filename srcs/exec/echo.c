/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:18:12 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/16 16:30:14 by fatilly          ###   ########lyon.fr   */
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
		printf("%s", str[pos]);
		if (str[pos + 1])
			printf(" ");
		pos++;
	}
	if (n == 0)
		printf("\n");
}
