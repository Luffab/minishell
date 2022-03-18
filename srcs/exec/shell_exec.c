/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:38:07 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/18 14:34:11 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_exec1(t_shell *s, int i)
{
	if (str_is_equ(s->final_cmd[0], "export"))
	{
		s->return_status = built_in_export(s);
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "unset"))
	{
		built_in_unset(s, s->final_cmd);
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "pwd"))
	{
		s->return_status = built_in_pwd();
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "echo"))
	{
		built_in_echo(s->final_cmd);
		s->return_status = 0;
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "exit"))
		built_in_exit();
	return (i);
}

void	reinit_dup(t_shell *s)
{
	dup2(s->save_in, STDIN_FILENO);
	dup2(s->save_out1, STDOUT_FILENO);
	dup2(s->save_out2, STDOUT_FILENO);
}

void	shell_exec(t_shell *s)
{
	int	i;

	i = 0;
	in_delimiteur(s);
	init_fd(s);
	if (s->r_chev > 0 || s->l_schev > 0)
	{
		if (!in_redirect(s))
			s->return_status = 1;
	}
	if (str_is_equ(s->final_cmd[0], "env"))
	{
		built_in_env();
		s->return_status = 0;
		i++;
	}
	if (str_is_equ(s->final_cmd[0], "cd"))
	{
		s->return_status = built_in_cd(s->final_cmd[1]);
		i++;
	}
	i = shell_exec1(s, i);
	if (i == 0 && s->final_cmd[0])
		exec_cmd(s);
	reinit_dup(s);
}
