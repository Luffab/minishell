/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:27:05 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/06 18:29:19 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_get_args(t_shell *s, t_chev *ch)
{
	s->str = ft_substr(ch->str, 0, ft_strlen(ch->str));
	s->final_cmd = malloc(sizeof(char *) * (count_args(s->str) + 1));
	if (ch->str)
		free(ch->str);
	ch->str = NULL;
}

int	init_o_chev(t_chev *ch, t_shell *s)
{
	int	i;

	i = -1;
	ch->new_line = NULL;
	ch->start = NULL;
	ch->tab = malloc(sizeof(char *) * (count_o_chev(s, ch) + 1));
	s->tab_o_chev = malloc(sizeof(char *) * ((s->l_schev + s->r_chev) * 2 + 1));
	return (find_1st_o_chev(ch->str, i, ch));
}

int	init_l_dchev(char *cell, t_chev *ch, t_shell *s)
{
	int	i;

	i = -1;
	ch->start = NULL;
	ch->tab = malloc(sizeof(char *) * (count_l_dchev(cell, s) + 1));
	s->tab_l_dchev = malloc(sizeof(char *) * (s->l_dchev + 1));
	return (find_1st_l_dchev(cell, i, ch));
}

void	re_init_var(t_shell *s)
{
	s->r_chev = 0;
	s->l_schev = 0;
	s->l_dchev = 0;
	s->tab_l_dchev = NULL;
	s->tab_o_chev = NULL;
	s->str = NULL;
	s->path = NULL;
}

void	init_var(t_shell *s)
{
	s->delimiteur = NULL;
	s->ind_in_redir = 0;
	s->ind_out_redir = 0;
	s->nb_delimit = 0;
	s->r_chev = 0;
	s->l_schev = 0;
	s->l_dchev = 0;
	s->tab_l_dchev = NULL;
	s->tab_o_chev = NULL;
	s->tab = NULL;
	s->str = NULL;
	s->path = NULL;
	s->pid = 0;
	s->in_pipe = 0;
}
