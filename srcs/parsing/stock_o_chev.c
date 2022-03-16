/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_o_chev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <dpuccion@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:51:18 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/11 18:50:14 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_o_chev_word(t_shell *s, t_chev *ch, int k, int c)
{
	int		i;
	int		start;

	i = 0;
	while (ch->new_line[i] == ' ')
		i++;
	start = i;
	while (ch->new_line[i])
	{
		if (ch->new_line[i] == ' ')
			break ;
		if (ch->new_line[i] == '\'')
			i = get_squote(ch->new_line, i, ch);
		else if (ch->new_line[i] == '\"')
			i = get_dquote(ch->new_line, i, ch);
		else
			add_char(ch->new_line, i, ch);
		i++;
	}
	ch->tab[c] = ft_substr(ch->new_line, i, ft_strlen(ch->new_line) - i);
	s->tab_o_chev[k] = ft_substr(ch->str, 0, ft_strlen(ch->str));
	free(ch->str);
	return (1);
}

int	stock_o_chev(t_shell *s, t_chev *ch)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (ch->tab[++i])
	{
		j = 0;
		if (ch->tab[i][j] == '>' && ch->tab[i][j + 1] == '>')
		{
			s->tab_o_chev[k++] = ft_substr(ch->tab[i], 0, 2);
			j = j + 2;
		}
		else if (ch->tab[i][j] == '>' || ch->tab[i][j] == '<')
		{
			s->tab_o_chev[k++] = ft_substr(ch->tab[i], 0, 1);
			j++;
		}
		ch->new_line = ft_substr(ch->tab[i], j, (ft_strlen(ch->tab[i]) - 1));
		get_o_chev_word(s, ch, k++, i);
		reinit_o_chev(ch);
	}
	s->tab_o_chev[k] = 0;
	return (1);
}
