/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:43:31 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/18 13:35:52 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_execve(t_shell *s, char *path)
{
	execve(path, s->final_cmd, g_env);
	ft_putstr_fd("minishell: ", 2);
	perror(s->final_cmd[0]);
	exit(EXIT_FAILURE);
}

void	exec_cmd(t_shell *s)
{
	int		status;
	char	*path;

	signal(SIGINT, sig_handler);
	s->pid = fork();
	search_line_path(s);
	add_backslash(s);
	path = get_path(s);
	if (s->pid < 0)
		perror("fork");
	else if (s->pid == 0)
		exec_execve(s, path);
	else
		signal(SIGINT, SIG_IGN);
	waitpid(s->pid, &status, 0);
	s->return_status = WEXITSTATUS(status);
}
