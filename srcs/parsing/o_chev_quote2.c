/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_chev_quote2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:35:35 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/11 16:16:46 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_temp(t_chev *ch)
{
	ch->dol = 0;
	ch->rest = NULL;
	ch->temp = NULL;
	ch->count = 0;
}

int	get_o_dquote2(char *cell, int i, t_chev *ch)
{
	char	*rt;
	char	*var;

	var = NULL;
	if (cell[i] == '$' && cell[i + 1] == '?')
	{
		rt = ft_substr(cell, ch->start1, (i - ch->start1));
		ch->temp = ft_strjoindd(ch->temp, rt);
		join_ret(ch, var, 0);
		i++;
		ch->start1 = i + 1;
		ch->dol = i + 1;
	}
	return (i);
}

int	get_o_dquote3(char *cell, int i, t_chev *ch)
{
	char	*rt;
	char	*var;

	if (cell[i] == '$' && cell[i + 1] != '?')
	{
		rt = ft_substr(cell, ch->start1, (i - ch->start1));
		ch->temp = ft_strjoindd(ch->temp, rt);
		i++;
		ch->start2 = i;
		while ((cell[i] >= '0' && cell[i] <= '9')
			|| (cell[i] >= 'a' && cell[i] <= 'z')
			|| (cell[i] >= 'A' && cell[i] <= 'Z'))
			i++;
		ch->start1 = i;
		var = ft_substr(cell, ch->start2, i - ch->start2);
		i--;
		join_ret(ch, var, 1);
		ch->dol = i + 1;
	}
	return (i);
}

int	get_o_dquote(char *cell, int i, t_chev *ch)
{
	char	*var;

	ch->start1 = i + 1;
	ch->start2 = i + 1;
	init_temp(ch);
	var = NULL;
	while (cell[++i])
	{
		if (cell[i] == '\"')
		{	
			if (cell[i - 1] != '\"')
				fill_rest_temp(cell, ch->start1, i, ch);
			else if (cell[i - 1] == '\"')
				ch->temp = ft_strdup("");
			break ;
		}
		i = get_o_dquote2(cell, i, ch);
		i = get_o_dquote3(cell, i, ch);
	}
	join_and_free(ch);
	return (i);
}
