/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luffab <luffab@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:56:49 by luffab            #+#    #+#             */
/*   Updated: 2022/02/07 14:50:18 by luffab           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(void)
{
	int		ret;
	char	*line;
	int		fd;

	ret = 1;
	ft_putstr_fd("$> ", 1);
	fd = open("test", O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("cmd = %s\n", line);
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