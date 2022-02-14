/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:29 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/14 14:51:56 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t exitSig = 0;
volatile sig_atomic_t feedExitSig = 0;

void    sig_handler(int sig)
{
    if (sig == SIGINT)
    {
        printf("\n$> ");
        signal(SIGINT, sig_handler);
    }
}