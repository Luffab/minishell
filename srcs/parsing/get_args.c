/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:56:28 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/11 15:37:57 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\'' || str[i] == '\"')
			i = skip_quote(str, i);
		while (str[i] != ' ' && str[i])
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] || str [i] == 0)
			ret++;
	}
	return (ret);
}

char	*unquote_args(char *cmd, t_chev *ch)
{
	int		i;
	char	*ret;

	i = 0;
	while (cmd[i])
	{
		ch->ret = 0;
		i = check_dollar(cmd, i, ch);
		if (cmd[i] == '\'' && ch->ret == 0)
			i = get_squote(cmd, i, ch);
		else if (cmd[i] == '\"' && ch->ret == 0)
			i = get_o_dquote(cmd, i, ch);
		else if (ch->ret == 0)
			add_char(cmd, i, ch);
		if (cmd[i] == '\0')
			break ;
		i++;
	}
	ret = ft_substr(ch->str, 0, ft_strlen(ch->str));
	return (ret);
}

int	find_space(char *str, int i)
{
	while (str[i])
	{
		i = skip_quote(str, i);
		if (str[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

int	get_args(t_shell *s, t_chev *ch)
{
	int		i;
	int		j;
	int		start;
	char	*cmd;

	i = 0;
	j = 0;
	start = 0;
	init_get_args(s, ch);
	while (s->str[i])
	{
		while (s->str[i] == ' ')
			i++;
		start = i;
		i = find_space(s->str, i);
		cmd = ft_substr(s->str, start, i - start);
		s->final_cmd[j] = unquote_args(cmd, ch);
		reinit_ch2(ch, s, j);
		free (cmd);
		while (s->str[i] == ' ')
			i++;
		j++;
	}
	s->final_cmd[j] = 0;
	return (1);
}
