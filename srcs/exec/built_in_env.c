/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:34:23 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/18 14:05:00 by fatilly          ###   ########lyon.fr   */
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
	if (!ft_strrchr(str, '='))
		return ;
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

int	built_in_export(t_shell *s)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (!s->final_cmd[1])
		sort_env();
	while (s->final_cmd[++i])
	{
		if (s->final_cmd[i][0] == '=' || (s->final_cmd[i][0] >= '0'
				&& s->final_cmd[i][0] <= '9'))
		{
			printf("minishell: export: `%s': not a valid identifier\n", s->final_cmd[i]);
			status = 1;
		}
		else
			built_in_export_one_str(s, s->final_cmd[i]);
	}
	if (status == 1)
		return (1);
	return (0);
}

void	change_shlvl(void)
{
	char	*shlvl;
	int		nb;
	int		line;

	shlvl = getenv("SHLVL");
	line = search_in_env("SHLVL");
	nb = ft_atoi(shlvl);
	nb++;
	shlvl = ft_itoa(nb);
	free(g_env[line]);
	g_env[line] = ft_strjoin("SHLVL=", shlvl);
}