/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:03:58 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/15 18:13:19 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reinit_o_chev(t_chev *ch)
{
	ch->str = NULL;
	ch->temp = NULL;
	if (ch->new_line)
		free (ch->new_line);
}

void	reinit_ch(t_chev *ch)
{
	ch->temp = NULL;
	ch->str = NULL;
}

void	reinit_ch2(t_chev *ch)
{
	if (ch->str)
		free(ch->str);
	ch->str = NULL;
}
