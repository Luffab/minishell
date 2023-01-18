/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_chev_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:43 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/11 16:13:26 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_ch_env(char *var, char **env)
{
	int		i;
	int		var_len;

	i = -1;
	var_len = ft_strlen(var);
	while (env[++i])
	{
		if (ft_strncmp(env[i], var, var_len) == 0
			&& env[i][var_len] == '=')
			return (i);
	}
	return (-1);
}

void	join_ret2(t_chev *ch, char *var)
{
	int		ind;
	int		i;
	char	*add;

	ch->ret = 2;
	i = 0;
	ind = search_ch_env(var, ch->ch_env);
	if (ind > -1)
	{
		while (ch->ch_env[ind][i] != '=')
			i++;
		i++;
		add = ft_strdup(ch->ch_env[ind] + i);
		ch->temp = ft_strjoind(ch->temp, add);
		free(add);
		ch->count++;
	}
	else if (ind == -1 && !var[0])
		ch->temp = ft_strjoind(ch->temp, "$");
	free(var);
}

void	join_ret(t_chev *ch, char *var, int nb)
{
	char	*add;
	int		i;

	i = 0;
	if (nb == 0)
	{
		ch->ret = 1;
		add = ft_itoa(g_return_status);
		ch->temp = ft_strjoind(ch->temp, add);
		free(add);
	}
	else
		join_ret2(ch, var);
}

void	fill_rest_temp(char *cell, int start1, int i, t_chev *ch)
{
	if (ch->ret == 0)
		ch->temp = ft_substr(cell, start1, (i - start1));
	else
	{
		ch->rest = ft_substr(cell, ch->dol, (i - ch->dol));
		ch->temp = ft_strjoind(ch->temp, ch->rest);
		if (ch->rest)
			free(ch->rest);
	}
}

void	join_and_free(t_chev *ch)
{
	if (ch->temp)
		ch->str = ft_strjoind(ch->str, ch->temp);
	if (ch->temp)
		free(ch->temp);
}
