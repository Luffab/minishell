/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:28:28 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/11 15:35:15 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_dtab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
				free(tab[i]);
			i++;
		}
		if (tab)
			free(tab);
	}
}

void	free_parsing(t_shell *s, t_chev *ch)
{
	if (s->str)
		free(s->str);
	if (ch->str)
		free(ch->str);
	if (ch->new_line)
		free(ch->new_line);
	if (s->tab_o_chev)
		free_dtab(s->tab_o_chev);
	if (s->tab_l_dchev)
		free_dtab(s->tab_l_dchev);
	if (s->final_cmd)
		free_dtab(s->final_cmd);
}

int	quote_error(t_shell *s, int j)
{
	s->tab[j] = 0;
	return (0);
}
