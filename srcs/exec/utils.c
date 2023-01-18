/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:36:52 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/09 13:05:17 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*malloc_wordd(char *s1, char *s2)
{
	char	*str;

	str = (char *)malloc((ft_strlen(s1)
				+ ft_strlen(s2)) * sizeof(char) + 1);
	return (str);
}

char	*ft_strjoinnn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc_wordd(s1, s2);
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	init_fd(t_shell *s)
{
	int	i;

	i = 0;
	while (i < (s->r_chev + s->l_schev))
		i++;
	s->fd = malloc(sizeof(int) * i);
	i = -1;
	while (++i < (s->r_chev + s->l_schev))
		s->fd[i] = 0;
}

int	str_is_equ(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	**take_ch_env(t_shell *s)
{
	int		i;
	int		len;
	char	**env;

	i = 0;
	len = strlen_env(s->m_env);
	env = malloc(sizeof(char *) * len + 1);
	while (s->m_env[i])
	{
		env[i] = ft_strdup(s->m_env[i]);
		i++;
	}
	env[i] = 0;
	return (env);
}
