/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:06:49 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/08 17:08:59 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	boucle_pipe(t_shell *s, int j, int *pipefd)
{
	signal(SIGINT, pipe_handler);
	signal(SIGQUIT, pipe_handler);
	dup2(s->in_pipe, 0);
	if (s->tab[j + 1] != NULL)
		dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	shell_exec(s, j);
	exit(g_return_status);
}

void	multi_pipe(t_shell *s, int j)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	pipe(pipefd);
	pid = fork();
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
		boucle_pipe(s, j, pipefd);
	else
	{
		waitpid(pid, &status, 0);
		g_return_status = WEXITSTATUS(status);
		if (g_return_status != 0 && s->tab[j + 1] == NULL)
			g_return_status = 127;
		else if (g_return_status == 875)
			g_return_status = 131;
		else if (g_return_status == 874)
			g_return_status = 130;
		else
			g_return_status = 0;
		close(pipefd[1]);
		s->in_pipe = pipefd[0];
	}
}
