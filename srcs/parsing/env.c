/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:23:19 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/15 19:09:26 by fatilly          ###   ########lyon.fr   */
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
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], "PATH=", 5) == 0)
		{
			j = ft_strlen(g_env[i]);
			line_path = ft_substr(g_env[i], 5, j);
		}
		i++;
	}
	s->path = ft_split(line_path, ':');
	//free(line_path);
}

int	search_in_env(char *var)
{
	int		i;
	int		var_len;

	i = -1;
	var_len = ft_strlen(var);
	while (g_env[++i])
	{
		if (ft_strncmp(g_env[i], var, var_len) == 0
			&& g_env[i][var_len] == '=')
			return (i);
	}
	return (0);
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
