/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:53:30 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/16 16:54:36 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**remove_env(void)
{
	char	**env;
	int		i;
	int		j;
	int		size;

	i = -1;
	j = 0;
	size = strlen_env(g_env);
	env = malloc((sizeof(char *) * size + 1));
	while (g_env[++i])
	{
		if (!g_env[i][0])
			i++;
		env[j] = ft_strdup(g_env[i]);
		j++;
		free(g_env[i]);
	}
	env[j] = 0;
	free(g_env);
	return (env);
}

void	built_in_unset(t_shell *s, char **str)
{
	int	i;
	int	j;

	j = 0;
	while (s->final_cmd[++j])
	{
		i = search_in_env(str[j]);
		if (i > 0)
			g_env[i] = ft_strdup("");
		g_env = remove_env();
		s->env_len--;
	}
}
