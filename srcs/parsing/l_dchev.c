/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_dchev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <dpuccion@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:41 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/16 14:49:42 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_l_dchev(char *cell, t_shell *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	s->l_dchev = 0;
	while (cell[i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '<')
		{
			i++;
			if (cell[i] == '<')
			{
				if (cell[i + 1] == '<')
					return (-1);
				else
					ret++;
			}
		}
		i++;
	}
	s->l_dchev = ret;
	return (ret);
}

int	next_l_dchev(char *cell, int i)
{
	while (cell[i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '<')
		{
			i++;
			if (cell[i] == '<')
			{
				i = i - 2;
				return (i);
			}
		}
		i++;
	}
	return (i);
}

int	find_1st_l_dchev(char *cell, int i, t_chev *ch)
{
	while (cell[++i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '<' && cell[i + 1] == '<')
		{
			ch->start = ft_substr(cell, 0, i);
			return (i - 1);
		}
	}
	if (cell[i] == 0)
		ch->start = ft_substr(cell, 0, i);
	return (i - 1);
}

int	get_l_dchev(char *cell, t_shell *s, t_chev *ch)
{
	int		i;
	int		j;
	int		start;

	j = 0;
	i = -1;
	start = 0;
	i = init_l_dchev(cell, ch, s);
	while (cell[++i])
	{
		i = skip_quote(cell, i);
		if (cell[i] == '<' && cell[i + 1] == '<')
		{
			start = i + 2;
			i = next_l_dchev(cell, i + 2);
			ch->tab[j] = ft_substr(cell, start, i - start + 1);
			reinit_ch(ch);
			get_l_dchev_word(ch->tab[j], j, ch, s);
			j++;
		}
	}
	ch->tab[j] = 0;
	s->tab_l_dchev[j] = 0;
	return (1);
}
