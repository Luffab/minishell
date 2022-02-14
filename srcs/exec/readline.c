/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:11:52 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/14 13:32:19 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *rl_gets(t_shell *s)
{
    s->line_read = readline ("");

    if (s->line_read)
        add_history (s->line_read);
    return (s->line_read);
}