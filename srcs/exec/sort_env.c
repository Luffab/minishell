/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:13:16 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/11 13:31:06 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**dup_env(char **env)
{
	int		i;
	int		len;
	char	**temp_env;

	i = 0;
	len = strlen_env(env);
	temp_env = malloc(sizeof(char *) * len + 1);
	while (env[i])
	{
		temp_env[i] = ft_strdup(env[i]);
		i++;
	}
	temp_env[i] = 0;
	return (temp_env);
}

void	print_export(char **export)
{
	int		i;
	int		j;
	char	equ;

	i = 0;
	while (export[i])
	{
		equ = 1;
		j = 0;
		printf("declare -x ");
		while (export[i][j])
		{
			printf("%c", export[i][j]);
			if (export[i][j] == '=' && equ)
			{
				printf("\"");
				equ--;
			}
			j++;
		}
		if (!equ)
			printf("\"");
		printf("\n");
		i++;
	}
}

void	sort_env(t_shell *s)
{
	char	**dup;
	char	*tmp;
	int		i;
	int		j;

	dup = dup_env(s->m_env);
	i = 0;
	while (dup[i])
	{
		j = i + 1;
		while (dup[j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_export(dup);
	free_dtab(dup);
}

void	norm_export(t_shell *s, int len)
{
	s->m_env = realloc_m_env(len + 1, s);
	s->m_env[len] = ft_strdup(s->m_env[len - 1]);
	s->env_len++;
}
