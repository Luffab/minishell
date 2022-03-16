/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:34:23 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/16 16:54:40 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_env(void)
{
	int	i;

	i = -1;
	while (g_env[++i])
		printf("%s\n", g_env[i]);
}

int	var_exist(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '=')
	{
		line[i] = str[i];
		i++;
	}
	j = search_in_env(line);
	free(line);
	return (j);
}

void	built_in_export_one_str(t_shell *s, char *str)
{
	int	len;
	int	i;
	int	j;
	int	exist_ind;

	len = s->env_len;
	i = 0;
	j = 0;
	exist_ind = var_exist(str);
	if (exist_ind > 0)
		len = exist_ind + 1;
	else
	{
		g_env = realloc_m_env(len + 1);
		g_env[len] = ft_strdup(g_env[len - 1]);
		s->env_len++;
	}
	while (g_env[len - 1][j])
	{
		if (str[i] == '\'' || str[i] == '"')
			i++;
		g_env[len - 1][j++] = str[i++];
	}
}

void	built_in_export(t_shell *s)
{
	int	i;

	i = 0;
	if (!s->final_cmd[1])
		sort_env();
	while (s->final_cmd[++i])
	{
		if (s->final_cmd[i][0] == '=')
		{
			s->return_status = 1;
			i++;
		}
		if (!ft_strrchr(s->final_cmd[i], '='))
			i++;
		else
			built_in_export_one_str(s, s->final_cmd[i]);
	}
}
