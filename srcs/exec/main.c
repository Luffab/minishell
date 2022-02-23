/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:56:49 by luffab            #+#    #+#             */
/*   Updated: 2022/02/23 13:34:44 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(t_shell *s)
{
	char	*line_read;

	line_read = ft_strdup("");
	while (line_read)
	{
		line_read = readline("$> ");
		if (ft_strlen(line_read) > 0)
			add_history(line_read);
		if (ft_strncmp("env", line_read, 3) == 0)
			built_in_env(s);
		if (ft_strncmp("export", line_read, 6) == 0)
			built_in_export(s, "TEST=\"42\"");
		free(line_read);
	}
	printf("\n");
	if (line_read)
		free(line_read);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	if (ac > 1 && !av[1])
		return (1);
	t_shell s;
	take_env(&s, env);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	minishell_loop(&s);
}