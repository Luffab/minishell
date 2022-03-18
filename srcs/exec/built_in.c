/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:01:32 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/18 14:10:41 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in_cd(char *path)
{
	int		res;
	char	*user;
	char	*final_usr;
	int		ind;

	res = 0;
	ind = search_in_env("USER");
	while (g_env[ind][res] != '=')
		res++;
	user = ft_strdup(g_env[ind] + res + 1);
	final_usr = ft_strjoin("/Users/", user);
	if (!path)
		res = chdir(final_usr);
	else
		res = chdir(path);
	free(user);
	free(final_usr);
	if (res == -1)
	{
		perror("chdir()");
		return (1);
	}
	return (0);
}

int	built_in_pwd(void)
{
	char	*cwd;
	char	*res;
	size_t	alloc;

	alloc = sizeof(char) * 1024;
	res = (char *)malloc(alloc);
	cwd = getcwd(res, alloc);
	if (cwd != NULL)
		printf("%s\n", cwd);
	else
	{
		return (1);
		perror("getcwd()");
	}
	return (0);
}

void	built_in_exit(void)
{
	printf("exit\n");
	exit(0);
}
