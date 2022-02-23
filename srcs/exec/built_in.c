/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:01:32 by fatilly           #+#    #+#             */
/*   Updated: 2022/02/23 14:14:41 by fatilly          ###   ########lyon.fr   */
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
    size_t  allocSize;

    allocSize = sizeof(char) * 1024;
    res = (char *)malloc(allocSize);
    cwd = getcwd(res, allocSize);
	if (cwd != NULL)
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
    s->m_env = realloc_m_env(len + 1, s);
    s->m_env[len] = ft_strdup(s->m_env[len - 1]);
    while (s->m_env[len - 1][j])
    {
        if (str[i] == '\'' || str[i] == '"')
            i++;
        s->m_env[len - 1][j] = str[i];
        i++;
        j++;
    }
    s->env_len++;
}

void    built_in_env(t_shell *s)
{
    int i;

    i = -1;
    while (s->m_env[++i])
        printf("%s\n", s->m_env[i]);
}