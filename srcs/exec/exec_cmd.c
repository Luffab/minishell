/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:43:31 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/11 13:53:10 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_execve(t_shell *s, char *path)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	execve(path, s->final_cmd, s->m_env);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s->final_cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	return_stat(int status, t_shell *s, int j)
{
	if (g_return_status == 875)
		g_return_status = 131;
	else if (g_return_status == 874)
		g_return_status = 130;
	else if (s->tab[j + 1] == NULL && status == 0)
		g_return_status = 0;
	else
		g_return_status = WEXITSTATUS(status);
}

int	exec_cmd(t_shell *s, int j)
{
	int		status;
	char	*path;

	if ((ft_strcmp(s->final_cmd[0], "cat") == 0
			|| ft_strcmp(s->final_cmd[0], "grep") == 0
			|| ft_strcmp(s->final_cmd[0], "wc") == 0)
		&& s->nb_pipe < 1)
	{
		signal(SIGINT, fork_handler);
		signal(SIGQUIT, sig_handler);
	}
	if (ft_strcmp(s->final_cmd[0], "./minishell") == 0)
		signal(SIGINT, SIG_IGN);
	s->pid = fork();
	search_line_path(s);
	add_backslash(s);
	path = get_path(s);
	if (s->pid < 0)
		perror("fork");
	else if (s->pid == 0)
		exec_execve(s, path);
	waitpid(s->pid, &status, 0);
	return_stat(status, s, j);
	reinit_dup(s);
	return (j);
}
