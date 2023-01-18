/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:38:07 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/09 16:47:46 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_exec1(t_shell *s, int i)
{
	int	j;

	j = -1;
	if (str_is_equ(s->final_cmd[0], "export"))
	{
		g_return_status = built_in_export(s);
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "unset"))
	{
		built_in_unset(s, s->final_cmd);
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "pwd"))
	{
		g_return_status = built_in_pwd();
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "echo"))
	{
		built_in_echo(s->final_cmd);
		g_return_status = 0;
		i++;
	}
	return (i);
}

void	reinit_dup(t_shell *s)
{
	dup2(s->save_in, STDIN_FILENO);
	dup2(s->save_out1, STDOUT_FILENO);
	dup2(s->save_out2, STDOUT_FILENO);
}

void	shell_exec2(t_shell *s)
{
	if (s->l_dchev > 0)
	{
		in_delimiteur(s);
		g_return_status = WEXITSTATUS(s->del_status);
	}
	init_fd(s);
}

int	shell_exec3(t_shell *s, int i)
{
	if (str_is_equ(s->final_cmd[0], "env"))
	{
		built_in_env(s);
		g_return_status = 0;
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "cd"))
	{
		g_return_status = built_in_cd(s->final_cmd[1], s);
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "exit"))
	{
		i++;
		built_in_exit(s);
	}
	return (i);
}

int	shell_exec(t_shell *s, int j)
{
	int	i;

	i = 0;
	init_fd(s);
	if (s->r_chev > 0 || s->l_schev > 0)
	{
		if (!in_redirect(s))
		{
			g_return_status = 1;
			free(s->fd);
			return (0);
		}
	}
	i = shell_exec1(s, i);
	i = shell_exec3(s, i);
	if (i == 0 && s->final_cmd[0])
		j = exec_cmd(s, j);
	free(s->fd);
	reinit_dup(s);
	return (j);
}
