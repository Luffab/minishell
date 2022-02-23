/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:18:12 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/23 13:06:22 by fatilly          ###   ########lyon.fr   */
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
        i++;
    }
}

void    built_in_echo(char **str, int quote, int n)
{
    int pos;

    pos = 0;
    while (str[pos] != 0)
    {
        if (quote == 2)
            printf("%s", str[pos]);
        else
            built_in_echo_dq(str[pos]);
        pos++;
    }
    if (n == 0)
        ft_putstr_fd("\n", 1);
}