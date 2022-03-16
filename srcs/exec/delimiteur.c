/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiteur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:51:15 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/14 15:45:01 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_delimiteur(t_shell *s)
{
	char	*temp;
	char	*line;
	int		i;

	temp = ft_strdup("");
	line = ft_strdup("");
	i = 0;
	while (line && i < s->l_dchev)
	{
		line = readline("> ");
		if (ft_strncmp(line, s->tab_l_dchev[i], ft_strlen(line)) == 0
			&& ft_strlen(line) == ft_strlen(s->tab_l_dchev[i]))
			i++;
		else if (i == s->l_dchev - 1)
		{
			temp = ft_strjoin(temp, line);
			temp = ft_strjoin(temp, "\n");
		}
		if (line)
			free(line);
	}
	s->delimiteur = temp;
	free(temp);
}
