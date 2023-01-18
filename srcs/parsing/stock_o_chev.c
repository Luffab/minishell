/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_o_chev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:51:18 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/09 16:47:22 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dollar2(char *str, int i, t_chev *ch, char *add)
{
	int		start;
	int		ind;
	int		j;
	char	*var;

	start = i;
	j = 0;
	while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z'))
		i++;
	add = ft_substr(str, start, i - start);
	i--;
	ind = search_ch_env(add, ch->ch_env);
	free(add);
	if (ind > -1)
	{
		while (ch->ch_env[ind][j] != '=')
			j++;
		j++;
		var = ft_strdup(ch->ch_env[ind] + j);
		ch->str = ft_strjoind(ch->str, var);
		free(var);
	}
	return (i);
}

int	check_dollar(char *str, int i, t_chev *ch)
{
	char	*add;

	add = NULL;
	if (str[i] == '$' && str[i + 1])
	{
		i++;
		if (str[i] == '?')
		{
			ch->ret = 1;
			add = ft_itoa(g_return_status);
			ch->str = ft_strjoind(ch->str, add);
			free(add);
		}
		else
		{
			ch->ret = 2;
			i = check_dollar2(str, i, ch, add);
		}
	}
	return (i);
}

void	get_o_chev_word(t_shell *s, t_chev *ch, int k, int c)
{
	int		i;
	int		start;

	i = 0;
	while (ch->new_line[i] == ' ')
		i++;
	start = i;
	while (ch->new_line[i])
	{
		ch->ret = 0;
		i = check_dollar(ch->new_line, i, ch);
		if (ch->new_line[i] == ' ' && ch->ret == 0)
			break ;
		if (ch->new_line[i] == '\'' && ch->ret == 0)
			i = get_squote(ch->new_line, i, ch);
		else if (ch->new_line[i] == '\"' && ch->ret == 0)
			i = get_o_dquote(ch->new_line, i, ch);
		else if (ch->ret == 0)
			add_char(ch->new_line, i, ch);
		i++;
	}
	ch->tab[c] = ft_substr(ch->new_line, i, ft_strlen(ch->new_line) - i);
	s->tab_o_chev[k] = ft_substr(ch->str, 0, ft_strlen(ch->str));
	if (ch->str)
		free(ch->str);
}

void	stock_o_chev(t_shell *s, t_chev *ch)
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
		ch->new_line = ft_substrr(ch->tab[i], j, (ft_strlen(ch->tab[i]) - 1));
		get_o_chev_word(s, ch, k++, i);
		reinit_o_chev(ch);
	}
	s->tab_o_chev[k] = 0;
}
