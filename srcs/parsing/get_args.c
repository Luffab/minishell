/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <dpuccion@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:56:28 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/12 17:20:45 by dpuccion         ###   ########lyon.fr   */
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

char	*unquote_args(char *str, t_chev *ch)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (str[i])
	{
		if (str[i] == '\'')
			i = get_squote(str, i, ch);
		else if (str[i] == '\"')
			i = get_dquote(str, i, ch);
		else
			add_char(str, i, ch);
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
		reinit_ch2(ch);
		free(cmd);
		while (s->str[i] == ' ')
			i++;
		j++;
	}
	s->final_cmd[j] = 0;
	return (1);
}
