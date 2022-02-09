/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:01:32 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/09 14:17:59 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    built_in_cd(char *path)
{
    int res;

    res = chdir(path);
	if (res == -1)
		perror("chdir()");
}

void	built_in_pwd(void)
{
	char    *cwd;
    char    *res;

    cwd = malloc(sizeof(char) * 500);
    res = getcwd(cwd, sizeof(cwd));
	if (res != NULL)
	       printf("%s\n", cwd);
    else
		perror("getcwd()");
}

