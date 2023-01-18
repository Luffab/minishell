/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:24:10 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/11 15:26:01 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_first_cell(char *cell)
{
	int	i;

	i = 0;
	if (!cell)
		return (0);
	while (cell[i] == ' ')
		i++;
	if (cell[i] == 0)
		return (0);
	return (1);
}

int	check_cell(char *cell)
{
	int	i;

	i = 0;
	if (!cell)
		return (0);
	while (cell[i] == ' ')
		i++;
	if (cell[i] == 0)
		return (0);
	return (1);
}

int	check_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (check_cell(tab[i]) == 0)
			return (0);
		i++;
	}	
	return (1);
}

int	parsing(char *line_read, t_shell *s, int i)
{
	if (ft_split_pipe(line_read, s) == 0)
	{
		g_return_status = 1;
		if (s->tab)
			free_dtab(s->tab);
		return (0);
	}
	if ((check_first_cell(s->tab[0]) == 0) && !s->tab[1])
		return (0);
	if (check_tab(s->tab) == 0)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 1);
		if (s->tab)
			free_dtab(s->tab);
		g_return_status = 258;
		return (0);
	}
	if (parsing_cmd(s, i, line_read) == 0)
	{
		if (s->tab)
			free_dtab(s->tab);
		return (0);
	}
	free(s->tab);
	return (1);
}
