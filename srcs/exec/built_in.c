/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:01:32 by fatilly           #+#    #+#             */
/*   Updated: 2022/04/11 14:24:22 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in_cd(char *path, t_shell *s)
{
	int		res;
	char	*user;
	char	*final_usr;
	int		ind;

	res = 0;
	ind = search_in_env("USER", s);
	while (s->m_env[ind][res] != '=')
		res++;
	user = ft_strdup(s->m_env[ind] + res + 1);
	final_usr = ft_strjoin("/Users/", user);
	if (!path)
		res = chdir(final_usr);
	else
		res = chdir(path);
	free(user);
	free(final_usr);
	if (res == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
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
	free(cwd);
	return (0);
}

int	str_search_nb(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ')
		i++;
	j = i;
	while (str[i])
	{
		if (str[j] == '-' || str[j] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	built_in_exit(t_shell *s)
{
	if (str_search_nb(s->final_cmd[1]))
	{
		printf("exit\n");
		printf("minishell: exit: %s: numeric argument required\n",
			s->final_cmd[1]);
		exit(255);
	}
	else if (s->final_cmd[1] && s->final_cmd[2])
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		g_return_status = 1;
	}
	else if (s->final_cmd[1])
	{
		printf("exit\n");
		exit(ft_atoi(s->final_cmd[1]));
	}
	else
	{
		printf("exit\n");
		exit(0);
	}
}

int	is_export_valid(char *str)
{
	int	j;

	j = 0;
	while (str[j] && str[j] != '=')
	{
		if ((str[0] < 'A' || str[0] > 'Z')
			&& (str[0] < 'a' || str[0] > 'z'))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", str);
			return (0);
		}
		else if ((str[j] < 'A' || str[j] > 'Z')
			&& (str[j] < 'a' || str[j] > 'z')
			&& (str[j] < '0' || str[j] > '9'))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", str);
			return (0);
		}
		j++;
	}
	return (1);
}
