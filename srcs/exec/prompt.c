/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuccion <dpuccion@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:32:25 by fatilly           #+#    #+#             */
/*   Updated: 2022/03/23 17:00:37 by dpuccion         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_last_pwd(char *pwd)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen(pwd) - 1;
	j = ft_strlen(pwd) - 1;
	while (pwd[i] != '/')
		i--;
	new = ft_substr(pwd, i + 1, j);
	free(pwd);
	return (new);
}

char	*get_pwd(void)
{
	char	*pwd;
	char	*res;
	size_t	alloc;

	alloc = sizeof(char) * 1024;
	res = (char *)malloc(alloc);
	pwd = getcwd(res, alloc);
	if (pwd != NULL)
		return (pwd);
	return (NULL);
}

void	add_value(char **str, char *new_value)
{
	char	*tmp;

	tmp = ft_strjoin(*str, new_value);
	free(*str);
	*str = tmp;
}

void	print_prompt(char **prompt)
{
	char	*pwd;

	pwd = get_pwd();
	pwd = get_last_pwd(pwd);
	*prompt = ft_strdup(CYAN);
	add_value(prompt, pwd);
	add_value(prompt, " ");
	add_value(prompt, RESET);
	add_value(prompt, ARROW);
	free(pwd);
	add_value(prompt, RESET);
	add_value(prompt, " ");
}
