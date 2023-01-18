/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:29 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/08 15:25:29 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		g_return_status = 875;
		printf("Quit: 3\n");
	}
}

void	delimit_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("> \n");
		exit(1);
	}
}

void	fork_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_return_status = 874;
		printf("\n");
	}
}

void	pipe_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_return_status = 874;
		printf("\n");
		exit(0);
	}
	if (sig == SIGQUIT)
	{
		g_return_status = 875;
		printf("Quit: 3\n");
		exit(0);
	}
}
