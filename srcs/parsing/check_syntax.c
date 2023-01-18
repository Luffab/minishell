/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:38:33 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/25 18:06:20 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_space(char *cell, int i)
{
	while (cell[i] == ' ' && cell[i])
		i++;
	return (i);
}

char	check_space(char *cell)
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
				return (cell[i]);
			i = skip_quote(cell, i);
		}
		else if (cell[i] == '<' || cell[i] == '>')
		{
			i = skip_space(cell, i + 1);
			if (cell[i] == '<' || cell[i] == '>' || cell[i] == 0)
				return (cell[i]);
			i = skip_quote(cell, i);
		}
	}
	return (1);
}

int	check_syntax(char *cell)
{
	int		i;

	i = 0;
	while (cell[i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '<' && cell[i + 1] == '>')
			return (status_error1());
		if (cell[i] == '>' && cell[i + 1] == '<')
			return (status_error2());
		if (cell[i] == '>' && cell[i + 1] == '>' && cell[i + 2] == '>')
			return (status_error4());
		if (cell[i] == '>' && cell[i + 1] == '>' && cell[i + 2] == '<')
			return (status_error2());
		if (cell[i] == '<' && cell[i + 1] == '<' && cell[i + 2] == '<')
			return (status_error4());
		if (cell[i] == '<' && cell[i + 1] == '<' && cell[i + 2] == '>')
			return (status_error3());
		i++;
	}
	return (status_error5(cell));
}
