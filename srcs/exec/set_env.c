/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:55:11 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/09 18:48:45 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**realloc_m_env(int size, t_shell *s)
{
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (s->m_env[i] && i < size)
	{
		temp[i] = ft_strdup(s->m_env[i]);
		if (s->m_env[i])
			free(s->m_env[i]);
		i++;
	}
	temp[size] = 0;
	free(s->m_env);
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

void	copy_m_env(t_shell *s, char **env)
{
	int	i;

	i = 0;
	s->env_len = strlen_env(env);
	s->m_env = malloc(sizeof(char *) * s->env_len + 1);
	while (env[i])
	{
		s->m_env[i] = ft_strdup(env[i]);
		i++;
	}
	s->m_env[i] = 0;
}

void	take_env(t_shell *s, char **env)
{
	int	i;

	i = 0;
	if (!s->m_env)
	{
		s->env_len = strlen_env(env);
		s->m_env = malloc(sizeof(char *) * s->env_len + 1);
		while (env[i])
		{
			s->m_env[i] = ft_strdup(env[i]);
			i++;
		}
		s->m_env[i] = 0;
	}
}
