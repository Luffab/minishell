/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:23:19 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/09 18:16:45 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	search_line_path(t_shell *s)
{
	int		i;
	int		j;
	char	*line_path;

	i = 0;
	j = 0;
	while (s->m_env[i])
	{
		if (ft_strncmp(s->m_env[i], "PATH=", 5) == 0)
		{
			j = ft_strlen(s->m_env[i]);
			line_path = ft_substr(s->m_env[i], 5, j);
		}
		i++;
	}
	s->path = ft_split(line_path, ':');
}

int	search_in_env(char *var, t_shell *s)
{
	int		i;
	int		var_len;

	i = -1;
	var_len = ft_strlen(var);
	while (s->m_env[++i])
	{
		if (ft_strncmp(s->m_env[i], var, var_len) == 0
			&& s->m_env[i][var_len] == '=')
			return (i);
	}
	return (-1);
}

void	add_backslash(t_shell *s)
{
	int	i;

	i = 0;
	while (s->path[i])
	{
		s->path[i] = ft_strjoin(s->path[i], "/");
		i++;
	}
}

char	*get_path(t_shell *s)
{
	int		i;
	char	*path;

	i = 0;
	while (s->path[i])
	{
		path = ft_strjoinnn(s->path[i], s->final_cmd[0]);
		if (access(path, X_OK) == 0)
			return (path);
		if (path)
			free(path);
		i++;
	}
	return (s->final_cmd[0]);
}
