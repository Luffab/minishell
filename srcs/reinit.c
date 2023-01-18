/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:58 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/11 15:37:29 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ch(t_chev *ch)
{
	ch->str = NULL;
	ch->temp = NULL;
	ch->tab = NULL;
	ch->start = NULL;
	ch->new_line = NULL;
	ch->rest = NULL;
	ch->ret = -1;
	ch->dol = -1;
}

void	reinit_o_chev(t_chev *ch)
{
	if (ch->new_line)
		free (ch->new_line);
	ch->str = NULL;
	ch->temp = NULL;
	ch->new_line = NULL;
}

void	reinit_ch(t_chev *ch)
{
	ch->temp = NULL;
	ch->str = NULL;
}

void	reinit_ch2(t_chev *ch, t_shell *s, int j)
{
	if (!s->final_cmd[j])
		s->final_cmd[j] = ft_strdup("");
	if (ch->str)
		free(ch->str);
	ch->str = NULL;
}
