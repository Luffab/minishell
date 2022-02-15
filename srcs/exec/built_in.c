/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:01:32 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/15 15:37:02 by fatilly          ###   ########lyon.fr   */
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

void    built_in_export(t_shell *s, char *str)
{
    int len;
    int i;
    int j;

    len = s->env_len;
    i = 0;
    j = 0;
    s->m_env = realloc_m_env(len + 1);
    s->m_env[len] = ft_strdup(s->m_env[len - 1]);
    {
        if (str[i] == '\'' || str[i] == '"')
            i++;
        s->m_env[len - 1][j] = str[i];
        i++;
        j++;
    }
    s->env_len++;
}