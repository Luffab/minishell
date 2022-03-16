/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <dpuccion@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:38:33 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/11 16:51:02 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_space(char *cell, int i)
{
	while (cell[i] == ' ' && cell[i])
		i++;
	return (i);
}

int	check_space(char *cell)
{
	int	i;

	i = -1;
	while (cell[++i])
	{
		i = skip_quote(cell, i);
		if ((cell[i] == '<' && cell[i + 1] == '<')
			|| (cell[i] == '>' && cell[i + 1] == '>'))
		{
			i = skip_space(cell, i + 2);
			if (cell[i] == '<' || cell[i] == '>' || cell[i] == 0)
				return (0);
			i = skip_quote(cell, i);
		}
		else if (cell[i] == '<' || cell[i] == '>')
		{
			i = skip_space(cell, i + 1);
			if (cell[i] == '<' || cell[i] == '>' || cell[i] == 0)
				return (0);
			i = skip_quote(cell, i);
		}
	}
	return (1);
}

int	check_syntax(char *cell)
{
	int	i;

	i = 0;
	while (cell[i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '<' && cell[i + 1] == '>')
			return (0);
		if (cell[i] == '>' && cell[i + 1] == '<')
			return (0);
		if (cell[i] == '>' && cell[i + 1] == '>' && cell[i + 2] == '>')
			return (0);
		if (cell[i] == '>' && cell[i + 1] == '>' && cell[i + 2] == '<')
			return (0);
		if (cell[i] == '<' && cell[i + 1] == '<' && cell[i + 2] == '<')
			return (0);
		if (cell[i] == '<' && cell[i + 1] == '<' && cell[i + 2] == '>')
			return (0);
		i++;
	}
	if (check_space(cell) == 0)
		return (0);
	return (1);
}
