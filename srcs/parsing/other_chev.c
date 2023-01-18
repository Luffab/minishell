/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_chev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:20:29 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/14 14:17:00 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_o_chev(t_shell *s, t_chev *ch)
{
	int	i;

	i = 0;
	s->r_chev = 0;
	s->l_schev = 0;
	while (ch->str[i])
	{
		i = skip_quote(ch->str, i);
		if (ch->str[i] == '>')
		{
			if (ch->str[i + 1] == '>')
				i++;
			s->r_chev++;
		}
		else if (ch->str[i] == '<')
		{
			s->l_schev++;
		}
		i++;
	}
	return (s->r_chev + s->l_schev);
}

int	next_o_chev(char *cell, int i)
{
	while (cell[i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '>' || cell[i] == '<')
			return (i - 1);
		i++;
	}
	return (i);
}

int	find_1st_o_chev(char *cell, int i, t_chev *ch)
{
	while (cell[++i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '<' || cell[i] == '>')
		{
			ch->start = ft_substr(cell, 0, i);
			return (i - 1);
		}
	}
	if (cell[i] == 0)
		ch->start = ft_substr(cell, 0, i);
	return (i - 1);
}

int	get_other_chev(t_shell *s, t_chev *ch)
{
	int	i;
	int	j;
	int	start;

	i = -1;
	j = 0;
	start = 0;
	i = init_o_chev(ch, s);
	while (ch->str[++i])
	{
		i = skip_quote(ch->str, i);
		if (ch->str[i] == '>' || ch->str[i] == '<')
		{
			start = i;
			if (ch->str[i] == '>' && ch->str[i + 1] == '>')
				i++;
			i = next_o_chev(ch->str, i + 1);
			ch->tab[j] = ft_substr(ch->str, start, i - start + 1);
			j++;
		}
	}
	ch->tab[j] = 0;
	return (1);
}
