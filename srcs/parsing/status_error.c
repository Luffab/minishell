/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:48:59 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/25 18:07:42 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	status_error1(void)
{
	g_return_status = 258;
	ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
	return (0);
}

int	status_error2(void)
{
	g_return_status = 258;
	ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 2);
	return (0);
}

int	status_error3(void)
{
	g_return_status = 258;
	ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
	return (0);
}

int	status_error4(void)
{
	g_return_status = 1;
	ft_putstr_fd("minishell: `>>>' and `<<<' are not accepted\n", 2);
	return (0);
}

int	status_error5(char *cell)
{
	char	c;

	c = check_space(cell);
	if (c == 0)
		return (status_error1());
	else if (c == '<')
		return (status_error2());
	else if (c == '>')
		return (status_error3());
	return (1);
}
