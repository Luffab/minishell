/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:28:28 by dpuccion          #+#    #+#             */
/*   Updated: 2022/03/15 17:14:47 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_dtab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

//void	free_ttab(t_shell *s)
//{
//	int	i;
//	int	j;
//	
//	i = 0;
//	while (s->cmd[i])
//	{
//		j = 0;
//		while (s->cmd[i][j])
//		{
//			free(s->cmd[i][j])
//			j++;
//		}
//		free (s->cmd[i])
//		i++;
//	}
//	free(s->cmd);
//}