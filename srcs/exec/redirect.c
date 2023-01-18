/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:00:52 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/25 17:50:19 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_redir(char *line, int fd, int nb, t_shell *s)
{
	if (nb == 0)
	{
		if (!int_redirect(fd, line, s))
			return (1);
	}
	else if (nb == 1)
		out_redirect_sc(fd, line, s);
	else if (nb == 2)
		out_redirect_dc(fd, line, s);
	return (0);
}

void	boucle_redir1_bis(t_shell *s)
{
	if (ft_strncmp(">>", s->tab_o_chev[s->str_chev_ind], 2) == 0)
	{
		s->str_chev_ind++;
		s->ind_out_redir++;
		if (s->ind_out_redir == s->r_chev)
			last_redir(s->tab_o_chev[s->str_chev_ind], s->fd[s->fd_ind], 2, s);
		else
		{
			s->fd[s->fd_ind] = open(s->tab_o_chev[s->str_chev_ind],
					O_CREAT | O_WRONLY | O_APPEND, 0664);
			s->fd_ind++;
		}
	}
}

void	boucle_redir_1(t_shell *s)
{
	if (s->tab_o_chev[s->str_chev_ind][0] == '>'
		&& ft_strlen(s->tab_o_chev[s->str_chev_ind]) == 1)
	{
		s->str_chev_ind++;
		s->ind_out_redir++;
		if (s->ind_out_redir == s->r_chev)
			last_redir(s->tab_o_chev[s->str_chev_ind], s->fd[s->fd_ind], 1, s);
		else
		{
			s->fd[s->fd_ind] = open(s->tab_o_chev[s->str_chev_ind],
					O_CREAT | O_WRONLY | O_TRUNC, 0664);
			s->fd_ind++;
		}
	}
	boucle_redir1_bis(s);
}

int	in_redirect_bis(t_shell *s)
{
	if (ft_strncmp("<", s->tab_o_chev[s->str_chev_ind], 1) == 0)
	{
		s->ind_in_redir++;
		s->str_chev_ind++;
		if (s->ind_in_redir == s->l_schev)
			g_return_status = last_redir(s->tab_o_chev[s->str_chev_ind],
					s->fd[s->fd_ind], 0, s);
		else
		{
			if ((!access(s->tab_o_chev[s->str_chev_ind], F_OK)) == 0
				&& (s->ind_in_redir != s->l_schev))
			{
				printf("minishell: %s: No such file or directory\n",
					s->tab_o_chev[s->str_chev_ind]);
				return (0);
			}
			s->fd[s->fd_ind] = open(s->tab_o_chev[s->str_chev_ind],
					O_RDONLY);
			s->fd_ind++;
		}
		if (g_return_status == 1)
			return (0);
	}
	return (1);
}

int	in_redirect(t_shell *s)
{
	s->str_chev_ind = -1;
	s->fd_ind = 0;
	while (s->tab_o_chev[++s->str_chev_ind])
	{
		if (!in_redirect_bis(s))
		{
			g_return_status = 1;
			return (0);
		}
		boucle_redir_1(s);
	}
	close_fd(s->fd, s->fd_ind);
	g_return_status = 0;
	return (1);
}
