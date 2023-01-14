/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/12 22:20:24 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# define LSH_TOK_BUFSIZE 64
# define LSH_TOK_DELIM " \"\t\r\n\a"
# define TMP_FILE "./text.txt"

# define CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\033[0;31m"
# define DICT_LEN 256

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include "Libft/libft.h"

# define EXIT_SYNTAX_ERROR 258
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CTRL_D 130

typedef struct s_shelldup
{
	int	std_in;
	int	std_out;
	int	f_in;
	int	f_out;
}	t_shelldup;

typedef struct s_pipe_var
{
	t_list	*temp;
	pid_t	pid;
	int		*fd;
	int		i;
	int		j;
	char	**cmd;
	char	*path;
}			t_pipe_var;

typedef struct s_env
{
	t_list	*g_env;
	int		exit_status;
}	t_env;

t_env	g_list;
typedef struct s_builtin_str
{
	char	**builtin_str;
}	t_builtin_str;

typedef struct s_temp_var
{
	int		i;
	int		j;
	int		k;
	int		t;
	int		l;
	int		flag;

	char	*s;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;
	char	*tmp5;
	char	**tmp_2ar;
}			t_temp_var;
typedef struct s_redir_var
{
	char	*temp;
	int		fd;
	int		k;
	int		flags;
	char	*file;
	int		j;
	int		m;

}			t_redir_var;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

int		count(char *str, char c);
t_list	**add_list(char **str, t_list **mini);
void	ft_putnstr(char *str, int n);
char	*line_edit(char *line);
void	lsh_loop(t_builtin_str *str);
int		lsh_launch(char **args, t_builtin_str *str);
char	**lsh_split_line(char *line);
void	init(t_builtin_str *str);
t_list	*get_new_env(char **env);
void	lsh_loop(t_builtin_str *str);
char	**lsh_split_line(char *line);
int		get_cmd_num(const char *str);
char	*command(char *str, int *i, char *args, int j);
char	*q_dollar(char *tmp);
int		dollar_query(char *tmp);
char	*dollar(char *str, int *i);
char	*get_value(char *key);
int		check_valid(char *line);
char	*parser(char *str);
char	*double_quotes(char *str, int *i);
char	*slash(char *str, int *i);
char	*quotes(char *str, int *i);
char	*get_value(char *key);
void	lsh_cd(char **arr);
int		lsh_exit(char **args);
int		lsh_execute(char **args, t_builtin_str *str);
int		lsh_num_builtins(t_builtin_str *str, char *args);
void	export(char **args);
void	pwd(void);
void	echo(char **arr);
void	unset(char **args);
int		lsh_launch(char **args, t_builtin_str *str);
char	*find_path(char *cmdline);
char	*find_value(char *key);
void	ft_free_str(char **str);
int		exp_check(char *str);
void	unset_exp(char **args);
void	export_env(void);
void	env(void);

char	**mem_wide(char **arr, int size);
void	*ft_realloc(void *ptr, size_t size);
char	*ft_new_left_str(char *left_str);
char	*ft_search_n_str(int fd, char *left_str);
char	*ft_get_one_line(char *left_str);
void	*ft_realloc(void *ptr, size_t size);
// char *get_next_line(int fd);
char	*dolar_sp(char *arr);
char	*env_find_value(char *key);
char	*my_strtok(char *str, char *delim);
char	*eq_cut(char *s1);
int		exp_env_check(char *str);
int		ft_line_check(char *line);
void	dq_loop(char **args);
void	line_write(char *line);
// signal
void	ctrl_d(void);
void	ctrl_c(int sig);
void	sig_handler(int sig_num);
void	sig_handler_heredoc(int sig_num);
void	signals(int signum);
int		ft_argslen(char **args);
// dir
void	check_dir(char *str);
int		redirect_in(char **str, int i);
int		redirect_out(char **str, int i);
void	redir2_out_handle(char **str, int i);
void	redir_out_handle(char **str, int i);
int		check_another_redir(char **str, int i);
void	redir2_in_handle(char **str, int i);
void	redir_in_handle(char **str, int i);
void	mixed_redir(char *str, char *temp, int fd);
void	mixed_redir2(char *str, char *temp, int fd);
void	here_doc(char *file, char *eof);
void	execute_dir(char *s, int fd, int i);
void	exec_redir(char *s, int fd, int i);
char	*sub_redir(char **str, int i);
void	here_doc2(char *file, char *eof);
void	ft_putstrendl_fd(char *s, int fd);
void	execsimple(char **parse);
int		process_string(char *str);
void	no_input_redir(int fd);
// pipes
void	pipe_handle(char *str, int n_pipe);
//free
void	ft_free_list(t_list **list);
void	run_signals(int sig);
//echo_utils
void	print_double_quote(char **arr, int *i);
void	print_single_quote(char **arr, int *i);
void	print_mixed_quote(char **arr, int *i);
//command_utils
char	*add_space(void);
char	*handle_end_of_string(char *str, int j, int i);
char	*handle_double_quotes(char *str, int j, int *i, char *tmp);
char	*handle_single_quotes(char *str, int j, int *i, char *tmp);
char	*handle_dollar_sign(char *str, int j, int *i);
char	*handle_other_cases(char *str, int j, int *i);

#endif