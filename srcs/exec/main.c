/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:56:49 by luffab            #+#    #+#             */
/*   Updated: 2022/02/09 15:16:36 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(void)
{
	int		ret;
	char	*line;

	ret = 1;
	ft_putstr_fd("$> ", 1);
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		ft_putstr_fd("$> ", 1);
	}
	printf("Bye \n");
	return (1);
}

int	main()
{
	/*if (ac > 1)
		return (1);*/
	minishell_loop();
}