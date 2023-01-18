/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:56:49 by luffab            #+#    #+#             */
/*   Updated: 2022/04/11 15:22:18 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_loop(t_shell *s)
{
	char	*line_read;
	char	*prompt;
	int		i;

	i = -1;
	line_read = NULL;
	while (line_read || ++i == 0)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, SIG_IGN);
		print_prompt(&prompt);
		line_read = readline(prompt);
		free(prompt);
		if (ft_strlen(line_read) > 0)
		{
			add_history(line_read);
			parsing(line_read, s, i);
		}
		if (line_read)
			free(line_read);
		init_var(s);
	}
	printf("exit\n");
	free(line_read);
	free_dtab(s->m_env);
}

int	main(int ac, char **av, char **env)
{
	t_shell	s;

	av = NULL;
	signal(SIGINT, sig_handler);
	if (ac > 1)
		return (1);
	g_return_status = 0;
	init_var(&s);
	take_env(&s, env);
	change_shlvl(&s);
	minishell_loop(&s);
	return (0);
}
