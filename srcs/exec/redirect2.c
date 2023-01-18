/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:02:24 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/08 15:07:54 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	out_redirect_dc(int fd, char *line, t_shell *s)
{
	s->last_out_fd = fd;
	s->tempout = open(line, O_CREAT | O_WRONLY | O_APPEND, 0664);
	s->save_out1 = dup(STDOUT_FILENO);
	close (STDOUT_FILENO);
	dup2(s->tempout, STDOUT_FILENO);
	s->fd_ind++;
}

void	out_redirect_sc(int fd, char *line, t_shell *s)
{
	s->last_out_fd = fd;
	s->tempout = open(line, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	s->save_out2 = dup(STDOUT_FILENO);
	close (STDOUT_FILENO);
	dup2(s->tempout, STDOUT_FILENO);
	s->fd_ind++;
}

int	int_redirect(int fd, char *line, t_shell *s)
{
	s->last_in_fd = fd;
	if ((!access(line, F_OK)) == 0)
	{
		printf("minishell: %s: No such file or directory\n", line);
		g_return_status = 1;
		return (0);
	}
	s->tempin = open(line, O_RDONLY);
	s->save_in = dup(STDIN_FILENO);
	close (STDIN_FILENO);
	dup2(s->tempin, STDIN_FILENO);
	s->fd_ind++;
	return (1);
}

void	close_fd(int *fd, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		if (fd[i] > 0)
			close(fd[i]);
	}
}
