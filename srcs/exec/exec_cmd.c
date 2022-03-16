/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:43:31 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/15 19:47:03 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_execve(t_shell *s, char *path)
{
	if (s->final_cmd[0])
	{
		execve(path, s->final_cmd, g_env);
		ft_putstr_fd("minishell: ", 2);
		perror(s->final_cmd[0]);
	}
	exit(EXIT_FAILURE);
}

void	exec_cmd(t_shell *s)
{
	pid_t	pid;
	int		status;
	char	*path;

	pid = fork();
	search_line_path(s);
	add_backslash(s);
	path = get_path(s);
	if (pid < 0)
		perror("fork");
	else if (pid == 0)
		exec_execve(s, path);
	waitpid(pid, &status, 0);
}
