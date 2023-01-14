/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:06:08 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/14 19:40:49 by mukeles          ###   ########.fr       */
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
void	sh_run(char **args, char *line, t_builtin_str *str);
void	executive_sh(char **args, char *line, t_builtin_str *str);
t_list	**add_list(char **str, t_list **mini);
void	ft_putnstr(char *str, int n);
char	*line_edit(char *line);
void	lsh_loop(t_builtin_str *str);
int		lsh_launch(char **args, t_builtin_str *str);
char	**lsh_split_line(char *line);
void	init(t_builtin_str *str);
t_list	*get_new_env(char **env);
int		get_cmd_num(const char *str);
char	*command(char *str, int *i, char *args, int j);
char	*dollar(char *str, int *i);
char	*get_value(char *key);
int		check_valid(char *line);
char	*parser(char *str);
void	lsh_cd(char **arr);
int		lsh_exit(void);
int		lsh_execute(char **args, t_builtin_str *str);
int		lsh_num_builtins(t_builtin_str *str, char *args);
void	export(char **args);
void	pwd(void);
void	echo(char **arr);
void	unset(char **args);
int		lsh_launch(char **args, t_builtin_str *str);
char	*find_path(char *cmdline);
char	*find_value(char *key);
int		find_path2(char *cmdline);
void	ft_free_str(char **str);
int		exp_check(char *str);
void	unset_exp(char **args);
void	export_env(void);
void	env(void);
char	*ft_new_left_str(char *left_str);
char	*ft_search_n_str(int fd, char *left_str);
char	*ft_get_one_line(char *left_str);
int		ft_line_check(char *line);
// signal
void	ctrl_d(void);
void	ctrl_c(int sig);
void	sig_handler(int sig_num);
void	sig_handler_heredoc(int sig_num);
void	signals(int signum);
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
//lsh_execute_ctrl
int		export_unset(char **args, int i);
int		pwd_env(int i);
int		cd_exit_echo(char **args, int i);
//exit_cd
void	dollar_mixed_quote(char **arr, int *i, int *k);

//is_echo
char	*check(char *s, int i);
int		is_echo(char *s);

void exec_builtin(char *str);
int is_builtin(char *tmp);
#endif