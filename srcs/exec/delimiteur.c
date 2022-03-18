/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiteur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:51:15 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/18 14:54:47 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_delimiteur(t_shell *s)
{
	char	*line;
	int		i;
	int 	status;

	line = ft_strdup("");
	i = 0;
	if (s->l_dchev > 0)
		s->pid = fork();
	if (s->pid == 0)
	{
		while (i < s->l_dchev)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGINT, delimit_handler);
			line = readline("> ");
			if (!line)
				exit(0) ;
			if (ft_strncmp(line, s->tab_l_dchev[i], ft_strlen(line)) == 0
				&& ft_strlen(line) == ft_strlen(s->tab_l_dchev[i]))
				i++;
			if (line)
				free(line);
		}
	}
	waitpid(s->pid, &status, 0);
}
