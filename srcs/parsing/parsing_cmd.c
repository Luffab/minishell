/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:24:36 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/11 14:38:26 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	join_rest(t_chev *ch)
{
	int	i;

	i = 0;
	while (ch->tab[i])
	{
		ch->str = ft_strjoindd(ch->str, ch->tab[i]);
		i++;
	}
	if (ch->start)
	{
		if (ch->str)
			ch->str = ft_strjoindd(ch->start, ch->str);
		else
			ch->str = ft_strjoindd(ch->str, ch->start);
	}
	if (ch->tab)
		free(ch->tab);
}

int	ft_split_cell(char *cell, t_shell *s, t_chev *ch)
{
	if (check_syntax(cell) == 0)
		return (0);
	init_ch(ch);
	get_l_dchev(cell, s, ch);
	ch->str = NULL;
	join_rest(ch);
	get_other_chev(s, ch);
	if (ch->str)
		free(ch->str);
	ch->str = NULL;
	stock_o_chev(s, ch);
	ch->str = NULL;
	join_rest(ch);
	get_args(s, ch);
	return (1);
}

int	boucle_pars_cmd(t_shell *s, int j, int i, t_chev *ch)
{
	while (s->tab[i])
	{
		if (ft_split_cell(s->tab[i], s, ch) == 0)
			return (0);
		if (s->l_dchev > 0)
		{
			signal(SIGINT, SIG_IGN);
			in_delimiteur(s);
			g_return_status = WEXITSTATUS(s->del_status);
		}
		if (s->nb_pipe >= 1)
		{
			multi_pipe(s, j);
			j++;
		}
		else
			shell_exec(s, j);
		free_parsing(s, ch);
		if (s->tab[i])
			free(s->tab[i]);
		i++;
	}
	return (1);
}

int	parsing_cmd(t_shell *s, int j, char *line_read)
{
	int		i;
	int		x;
	t_chev	ch;

	i = 0;
	j = 0;
	s->in_pipe = 0;
	ch.ch_env = take_ch_env(s);
	s->nb_pipe = count_cell(line_read) - 1;
	x = boucle_pars_cmd(s, j, i, &ch);
	if (ch.ch_env)
		free_dtab(ch.ch_env);
	return (x);
}
