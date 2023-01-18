/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:53:30 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/11 14:20:48 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**remove_env(t_shell *s)
{
	char	**env;
	int		i;
	int		j;
	int		size;

	i = -1;
	j = 0;
	size = strlen_env(s->m_env);
	env = malloc((sizeof(char *) * size + 1));
	while (s->m_env[++i])
	{
		if (!s->m_env[i][0])
		{
			free(s->m_env[i]);
			i++;
		}
		env[j] = ft_strdup(s->m_env[i]);
		j++;
		free(s->m_env[i]);
	}
	env[j] = 0;
	free(s->m_env);
	return (env);
}

int	is_unset_valid(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if ((str[0] < 'A' || str[0] > 'Z')
			&& (str[0] < 'a' || str[0] > 'z'))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", str);
			return (0);
		}
		else if ((str[j] < 'A' || str[j] > 'Z')
			&& (str[j] < 'a' || str[j] > 'z')
			&& (str[j] < '0' || str[j] > '9'))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", str);
			return (0);
		}
		j++;
	}
	return (1);
}

void	built_in_unset(t_shell *s, char **str)
{
	int	i;
	int	j;
	int	status;

	j = 0;
	while (s->final_cmd[++j])
	{
		i = search_in_env(str[j], s);
		if (i > 0)
		{
			free(s->m_env[i]);
			s->m_env[i] = ft_strdup("");
		}
		if (!is_unset_valid(s->final_cmd[j]))
		{
			status = 1;
			s->env_len++;
		}
		s->m_env = remove_env(s);
		s->env_len--;
	}
	if (status == 1)
		g_return_status = 1;
	g_return_status = 0;
}
