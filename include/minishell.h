/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:08:39 by luffab            #+#    #+#             */
/*   Updated: 2022/04/11 15:37:42 by fatilly          ###   ########lyon.fr   */
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
# include <pwd.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define BLACK "\001\e[1;30m\002"
# define RED "\001\e[1;31m\002"
# define GREEN "\001\e[1;32m\002"
# define YELLOW "\001\e[1;33m\002"
# define BLUE "\001\e[1;34m\002"
# define MAGENTA "\001\e[1;35m\002"
# define CYAN "\001\e[1;36m\002"
# define WHITE "\001\e[1;37m\002"

# define BG_BLACK "\001\e[40m\002"
# define BG_RED "\001\e[41m\002"
# define BG_GREEN "\001\e[42m\002"
# define BG_YELLOW "\001\e[43m\002"
# define BG_BLUE "\001\e[44m\002"
# define BG_MAGENTA "\001\e[45m\002"
# define BG_CYAN "\001\e[46m\002"
# define BG_WHITE "\001\e[47m\002"

# define RESET "\001\e[0m\002"
# define ARROW "\u27A1"

int	g_return_status;

typedef struct s_chev
{
	char	*str;
	char	*temp;
	char	**tab;
	char	**ch_env;
	char	*start;
	char	*new_line;
	char	*rest;
	int		ret;
	int		dol;
	int		count;
	int		start1;
	int		start2;
}				t_chev;

typedef struct s_shell
{
	char	**m_env;
	char	**first_env;
	char	**str_delimit;
	char	*delimiteur;
	char	**path;
	int		*fd;
	int		nb_delimit;
	int		nb_out_redir;
	int		nb_int_redir;
	int		ind_out_redir;
	int		ind_in_redir;
	int		env_len;
	int		str_chev_ind;
	int		fd_ind;
	int		in_pipe;
	int		out_pipe;
	int		fd_pipe[2];
	pid_t	pid;
	pid_t	pipe_pid;
	int		return_status;
	int		anc_out;
	int		anc_in;
	int		tempout;
	int		tempin;
	int		last_out_fd;
	int		last_in_fd;
	int		save_in;
	int		save_out1;
	int		save_out2;
	char	**tab;
	int		i;
	int		r_chev;
	int		l_schev;
	int		l_dchev;
	int		nb_pipe;
	int		c_cat;
	char	**tab_l_dchev;
	char	**tab_o_chev;
	char	**final_cmd;
	char	*str;
	int		del_status;
}				t_shell;

void	sig_handler(int sig);
void	int_handler(int sig);
void	pipe_handler(int sig);
void	take_env(t_shell *s, char **env);
int		strlen_env(char **env);
char	**realloc_m_env(int size, t_shell *s);
int		built_in_pwd(void);
void	built_in_echo(char **str);
int		built_in_cd(char *path, t_shell *s);
void	built_in_env(t_shell *s);
int		built_in_export(t_shell *s);
void	built_in_exit(t_shell *s);
void	built_in_unset(t_shell *s, char **str);
void	in_delimiteur(t_shell *s);
void	print_prompt(char **prompt);
void	ft_search_line_path(t_shell *s);
int		search_in_env(char *var, t_shell *s);
int		shell_exec(t_shell *s, int j);
int		in_redirect(t_shell *s);
void	out_redirect_dc(int fd, char *line, t_shell *s);
void	out_redirect_sc(int fd, char *line, t_shell *s);
int		int_redirect(int fd, char *line, t_shell *s);
int		check_first_tab(char *str);
int		exec_cmd(t_shell *s, int j);
char	*get_path(t_shell *s);
void	add_backslash(t_shell *s);
void	search_line_path(t_shell *s);
void	multi_pipe(t_shell *s, int j);
void	close_fd(int *fd, int nb);
void	init_fd(t_shell *s);
int		str_is_equ(char *s1, char *s2);
void	sort_env(t_shell *s);
void	change_shlvl(t_shell *s);
void	delimit_handler(int sig);
void	fork_handler(int sig);
void	free_parsing(t_shell *s, t_chev *ch);
void	reinit_dup(t_shell *s);
void	return_stat(int status, t_shell *s, int j);
int		is_export_valid(char *str);
void	norm_export(t_shell *s, int len);
int		is_unset_valid(char *str);

int		check_syntax(char *cell);
int		parsing(char *line_read, t_shell *s, int i);
int		check_tab(char **tab);
int		check_cell(char *cell);
int		ft_split_pipe(char *line, t_shell *s);
void	free_dtab(char **tab);
int		count_cell(char	*line);
int		skip_squote(char *line, int i);
int		skip_quote(char *line, int i);
int		parsing_cmd(t_shell *s, int i, char *line_read);
void	init_var(t_shell *s);
void	re_init_var(t_shell *s);
int		get_l_dchev_word(char *cell, int j, t_chev *ch, t_shell *s);
int		get_l_dchev(char *cell, t_shell *s, t_chev *ch);
int		get_other_chev(t_shell *s, t_chev *ch);
void	reinit_ch(t_chev *ch);
int		put_error(char *s, int ret);
void	stock_o_chev(t_shell *s, t_chev *ch);
int		get_dquote(char *cell, int i, t_chev *ch);
int		get_squote(char *cell, int i, t_chev *ch);
void	add_char(char *cell, int i, t_chev *ch);
int		count_l_dchev(char *cell, t_shell *s);
int		find_1st_l_dchev(char *cell, int i, t_chev *ch);
int		count_o_chev(t_shell *s, t_chev *ch);
int		find_1st_o_chev(char *cell, int i, t_chev *ch);
int		get_args(t_shell *s, t_chev *ch);
int		count_args(char *str);
int		get_o_dquote(char *cell, int i, t_chev *ch);
int		check_dollar(char *str, int i, t_chev *ch);
int		status_error1(void);
int		status_error2(void);
int		status_error3(void);
int		status_error4(void);
int		status_error5(char *cell);
char	check_space(char *cell);
char	*ft_substrr(char *src, int start, int len);
char	*ft_strjoind(char *s1, char *s2);
char	*ft_strjoindd(char *s1, char *s2);
char	**take_ch_env(t_shell *s);
int		search_ch_env(char *var, char **env);
int		get_o_dquote(char *cell, int i, t_chev *ch);
void	fill_rest_temp(char *cell, int start1, int i, t_chev *ch);
void	join_ret(t_chev *ch, char *var, int nb);
void	join_and_free(t_chev *ch);

void	init_ch(t_chev *ch);
int		init_l_dchev(char *cell, t_chev *ch, t_shell *s);
int		init_o_chev(t_chev *ch, t_shell *s);
void	reinit_o_chev(t_chev *ch);
void	init_get_args(t_shell *s, t_chev *ch);
void	reinit_ch2(t_chev *ch, t_shell *s, int j);
int		quote_error(t_shell *s, int j);

char	*ft_strjoinnn(char *s1, char *s2);

#endif