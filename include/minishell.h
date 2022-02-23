/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:08:39 by luffab            #+#    #+#             */
/*   Updated: 2022/02/23 13:29:59 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdbool.h>
# include <linux/limits.h>
# include <pwd.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct  s_shell
{
    char    **m_env;
    int     env_len;
}               t_shell;

void    sig_handler(int sig);
int     minishell_loop();
void	take_env(t_shell *s, char **env);
int     strlen_env(char **env);
char	**realloc_m_env(int size, t_shell *s);
void	built_in_pwd(void);
void    built_in_echo(char **str, int quote, int n);
void    built_in_cd(char *path);
void    built_in_env(t_shell *s);
void    built_in_export(t_shell *s, char *str);

#endif