/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:24:36 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/18 14:56:09 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_test(t_shell *s)
{
	int	i;

	i = 0;
	dprintf(1, "     > & >> = %d\n", s->r_chev);
	dprintf(1, "     << = %d\n", s->l_dchev);
	dprintf(1, "     < = %d\n", s->l_schev);
	while (s->final_cmd[i])
	{
		dprintf(1, "     cmd[%d]=[%s]\n", i, s->final_cmd[i]);
		i++;
	}
	i = 0;
	while (s->tab_l_dchev[i])
	{
		dprintf(1, "     l_d_chev[%d]=[%s]\n", i, s->tab_l_dchev[i]);
		i++;
	}
	i = 0;
	if (s->tab_o_chev[i] != 0)
	{
		while (s->tab_o_chev[i])
		{
			if (s->tab_o_chev[i] != 0)
				dprintf(1, "     o_chev[%d]=[%s]\n", i, s->tab_o_chev[i]);
			i++;
		}
	}
	dprintf(1, "\n");
}

void	join_rest(t_chev *ch)
{
	int	i;

	i = 0;
	while (ch->tab[i])
	{
		ch->str = ft_strjoin(ch->str, ch->tab[i]);
		free(ch->tab[i]);
		i++;
	}
	if (ch->start)
	{
		if (ch->str)
			ch->str = ft_strjoin(ch->start, ch->str);
		else
			ch->str = ft_strjoin(ch->str, ch->start);
		free(ch->start);
	}
	if (ch->tab)
		free(ch->tab);
}

int	ft_split_cell(char *cell, t_shell *s, t_chev *ch)
{
	if (check_syntax(cell) == 0)
	{
		ft_putstr_fd("1wrong syntax\n", 1);
		return (0);
	}
	if (get_l_dchev(cell, s, ch) == 0)
		return (0);
	ch->str = NULL;
	join_rest(ch);
	if (get_other_chev(s, ch) == 0)
		return (0);
	if (ch->str)
		free(ch->str);
	ch->str = NULL;
	if (stock_o_chev(s, ch) == 0)
		return (0);
	join_rest(ch);
	if (get_args(s, ch) == 0)
		return (0);
	//print_test(s);
	return (1);
}

int	parsing_cmd(t_shell *s)
{
	int		i;
	t_chev	ch;

	i = 0;
	while (s->tab[i])
	{
		if (ft_split_cell(s->tab[i], s, &ch) == 0)
			return (0);
		if (s->l_dchev > 0)
			signal(SIGINT, SIG_IGN);
		shell_exec(s);
		free_dtab(s->tab_o_chev);
		if (s->tab[i])
			free(s->tab[i]);
		i++;
	}
	return (1);
}
