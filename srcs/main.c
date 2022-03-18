/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:56:49 by luffab            #+#    #+#             */
/*   Updated: 2022/03/18 14:49:52 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(t_shell *s)
{
	char	*line_read;
	char	*prompt;

	line_read = ft_strdup("");
	while (line_read)
	{
		signal(SIGINT, sig_handler);
		print_prompt(&prompt);
		line_read = readline(prompt);
		if (ft_strlen(line_read) > 0)
		{
			add_history(line_read);
			parsing(line_read, s);
		}
		//free_dtab(s);
		free(s->tab);
		//free(line_read);
		init_var(s);
	}
	printf("exit\n");
	if (line_read)
		free(line_read);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_shell	s;

	av = NULL;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	if (ac > 1)
		return (1);
	init_var(&s);
	take_env(&s, env);
	change_shlvl();
	minishell_loop(&s);
}
