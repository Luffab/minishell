/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:45:20 by dpuccion          #+#    #+#             */
/*   Updated: 2022/04/11 15:35:56 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_dquote(char *line, int i)
{
	int	q;

	q = 0;
	i++;
	while (line[i])
	{
		if (line[i] == '\"')
		{	
			q = 1;
			break ;
		}
		i++;
	}
	if (q == 0)
	{
		ft_putstr_fd("quotes must be closed with the same quote type\n", 1);
		return (-1);
	}
	return (i);
}

int	skip_squote(char *line, int i)
{
	int	q;

	q = 0;
	i++;
	while (line[i])
	{
		if (line[i] == '\'')
		{	
			q = 1;
			break ;
		}
		i++;
	}
	if (q == 0)
	{
		ft_putstr_fd("quotes must be closed with the same quote type\n", 1);
		return (-1);
	}
	return (i);
}

int	skip_quote(char *line, int i)
{
	if (line[i] == '\"')
	{
		i++;
		while (line[i])
		{
			if (line[i] == '\"')
				break ;
			i++;
		}
	}
	else if (line[i] == '\'')
	{
		i++;
		while (line[i])
		{
			if (line[i] == '\'')
				break ;
			i++;
		}
	}
	return (i);
}

int	count_cell(char	*line)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	j = 0;
	ret = 1;
	while (line[++i])
	{
		i = skip_quote(line, i);
		if (line[i] == '|')
		{
			if (i == 0)
				ret++;
			else
			{
				if (line[i + 1] == 0 || line[i - 1])
					ret++;
			}
		}
		if (line[i] == 0 && line[i] != '|')
			ret++;
	}
	return (ret);
}

int	ft_split_pipe(char *line, t_shell *s)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	s->tab = malloc(sizeof(char *) * (count_cell(line) + 1));
	s->tab[count_cell(line)] = 0;
	while (line[++i])
	{
		if (line[i] == '\'')
			i = skip_squote(line, i);
		else if (line[i] == '\"')
			i = skip_dquote(line, i);
		if (i == -1)
			return (quote_error(s, j));
		if (line[i] == '|')
		{
			s->tab[j++] = ft_substr(line, k, i - k);
			k = i + 1;
		}
	}
	s->tab[j] = ft_substr(line, k, i - k);
	return (1);
}
