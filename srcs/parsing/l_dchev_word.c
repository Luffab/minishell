/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_dchev_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <dpuccion@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:58:13 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/11 18:07:49 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_char(char *cell, int i, t_chev *ch)
{
	char	*add;

	add = malloc(sizeof(char) * 2);
	add[0] = cell[i];
	add[1] = 0;
	ch->str = ft_strjoin(ch->str, add);
}

int	get_squote(char *cell, int i, t_chev *ch)
{
	int	q;
	int	start;

	q = 0;
	i++;
	start = i;
	ch->temp = NULL;
	while (cell[i])
	{
		if (cell[i] == '\'')
		{	
			q = 1;
			if (cell[i - 1] != '\'')
				ch->temp = ft_substr(cell, start, (i - start));
			break ;
		}
		i++;
	}
	if (ch->temp)
		ch->str = ft_strjoin(ch->str, ch->temp);
	if (ch->temp)
		free(ch->temp);
	return (i);
}

int	get_dquote(char *cell, int i, t_chev *ch)
{
	int	q;
	int	start;

	q = 0;
	i++;
	start = i;
	ch->temp = NULL;
	while (cell[i])
	{
		if (cell[i] == '\"')
		{	
			q = 1;
			if (cell[i - 1] != '\"')
				ch->temp = ft_substr(cell, start, (i - start));
			break ;
		}
		i++;
	}
	if (ch->temp)
		ch->str = ft_strjoin(ch->str, ch->temp);
	if (ch->temp)
		free(ch->temp);
	return (i);
}

int	l_dchev_word_loop(char *cell, t_chev *ch, int i)
{
	while (cell[i])
	{
		if (cell[i] == ' ')
			break ;
		if (cell[i] == '<' || cell[i] == '>')
			break ;
		if (cell[i] == '\'')
			i = get_squote(cell, i, ch);
		else if (cell[i] == '\"')
			i = get_dquote(cell, i, ch);
		else
			add_char(cell, i, ch);
		i++;
	}
	return (i);
}

int	get_l_dchev_word(char *cell, int j, t_chev *ch, t_shell *s)
{	
	int	i;

	i = 0;
	while (cell[i] == ' ')
		i++;
	i = l_dchev_word_loop(cell, ch, i);
	ch->tab[j] = ft_substr(ch->tab[j], i, (ft_strlen(ch->tab[j]) - i));
	s->tab_l_dchev[j] = ft_substr(ch->str, 0, ft_strlen(ch->str));
	free(ch->str);
	return (1);
}
