/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:55:11 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/15 19:45:25 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**realloc_m_env(int size)
{
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (g_env[i] && i < size)
	{
		temp[i] = ft_strdup(g_env[i]);
		if (g_env[i])
			free(g_env[i]);
		i++;
	}
	temp[size] = 0;
	free(g_env);
	return (temp);
}

int	strlen_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	copy_g_env(t_shell *s, char **env)
{
	int	i;

	i = 0;
	s->env_len = strlen_env(env);
	g_env = malloc(sizeof(char *) * s->env_len + 1);
	while (env[i])
	{
		g_env[i] = ft_strdup(env[i]);
		i++;
	}
	g_env[i] = 0;
}

void	take_env(t_shell *s, char **env)
{
	int	i;

	i = 0;
	if (!g_env)
	{
		s->env_len = strlen_env(env);
		g_env = malloc(sizeof(char *) * s->env_len + 1);
		while (env[i])
		{
			g_env[i] = ft_strdup(env[i]);
			i++;
		}
		g_env[i] = 0;
	}
}
