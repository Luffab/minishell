/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:18:12 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/09 15:07:06 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    built_in_echo_dq(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '$')
        {
            //fonction qui cherche variable et l'affiche
            while (str[i] != ' ')
                i++;
        }
        else
            ft_putchar_fd(str[i], 1);
    }
}

void    built_in_echo(char **str, int quote, int n)
{
    pos = 0;
    while (str != 0)
    {
        if (quote == 2)
            ft_putstr(str[pos], 1);
        else
            built_in_echo_dq(str[pos]);
        pos++;
    }
    if (n == 0)
        ft_putstr_fd("\n", 1);
}