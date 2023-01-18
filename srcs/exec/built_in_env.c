/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:34:23 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/11 14:24:44 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_env(t_shell *s)
{
	int	i;

	i = -1;
	while (s->m_env[++i])
		printf("%s\n", s->m_env[i]);
}

int	var_exist(char *str, t_shell *s)
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
	line[i] = 0;
	j = search_in_env(line, s);
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
	exist_ind = var_exist(str, s);
	if (exist_ind > 0)
		len = exist_ind + 1;
	else
		norm_export(s, len);
	while (str[i] != '\0')
	{
		free(s->m_env[len - 1]);
		s->m_env[len - 1] = malloc (sizeof(char) * ft_strlen(str) + 1);
		if (str[i] == '\'' || str[i] == '\"')
			i++;
		s->m_env[len - 1][j++] = str[i++];
	}
	s->m_env[len - 1][j] = 0;
}

int	built_in_export(t_shell *s)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (!s->final_cmd[1])
		sort_env(s);
	while (s->final_cmd[++i])
	{
		if (!is_export_valid(s->final_cmd[i]))
			status = 1;
		else
			built_in_export_one_str(s, s->final_cmd[i]);
	}
	if (status == 1)
		return (1);
	return (0);
}

void	change_shlvl(t_shell *s)
{
	char	*shlvl;
	int		nb;
	int		line;

	shlvl = getenv("SHLVL");
	line = search_in_env("SHLVL", s);
	nb = ft_atoi(shlvl);
	nb++;
	shlvl = ft_itoa(nb);
	free(s->m_env[line]);
	s->m_env[line] = ft_strjoin("SHLVL=", shlvl);
	free(shlvl);
}
