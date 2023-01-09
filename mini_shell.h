/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2023/01/09 13:23:48 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \"\t\r\n\a"
#define TMP_FILE "./text.txt"

# define CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\033[0;31m"
#define DICT_LEN 256

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include "Libft/libft.h"

#define EXIT_SYNTAX_ERROR 258
#define EXIT_CMD_NOT_FOUND 127
#define EXIT_CTRL_D 130


typedef struct shelldup
{
	int std_in;
	int std_out;
	int f_in;
	int f_out;

} shelldup;

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
	t_list *g_env;
	int exit_status;
} t_env;

t_env	g_list;

typedef struct s_builtin_str
{
	char **builtin_str;

} t_builtin_str;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 500
#endif

// utils
int count(char *str, char c);
t_list **add_list(char **str, t_list **mini);
void	ft_putnstr(char *str, int n);

void lsh_loop(t_builtin_str *str);					  // lsh_loop
int lsh_launch(char **args, t_builtin_str *str);	  // lsh_launch
char **lsh_split_line(char *line);					  // lsh_split_line
void init(t_builtin_str *str);						  // init
t_list *get_new_env(char **env);					  // get_new_env
void lsh_loop(t_builtin_str *str);					  // lsh_loop
char **lsh_split_line(char *line);					  // lsh_split_line
int get_cmd_num(const char *str);					  // get_cmd_num
char *command(char *str, int *i, char *args, int j);  // command
char *q_dollar(char *tmp);							  // q_dollar
int dollar_query(char *tmp);						  // dollar_query
char *dollar(char *str, int *i);					  // dollar
char *get_value(char *key);							  // dollar
char *replaceWord(char *s, char *oldW, char *newW);	  // replaceWord
int check_valid(char *line);						  // check_valid
char *parser(char *str);							  // parser
char *double_quotes(char *str, int *i);				  // double_quetes
char *slash(char *str, int *i);						  // slash
char *quotes(char *str, int *i);					  // quotes
char *get_value(char *key);							  // get_value
void lsh_cd(char **arr);							  // cd_exit_execute
int lsh_exit(char **args);							  // cd_exit_execute
int lsh_execute(char **args, t_builtin_str *str);	  // cd_exit_execute
int lsh_num_builtins(t_builtin_str *str, char *args); // cd_exit_execute
void export(char **args);							  // echo_pwd_env_export_unset
void pwd();											  // echo_pwd_env_export_unset
void echo(char **arr);								  // echo_pwd_env_export_unset
void unset(char **args);							  // echo_pwd_env_export_unset
int lsh_launch(char **args, t_builtin_str *str);	  // lsh_launch
char *find_path(char *cmdline);						  // find_path_value
char *find_value(char *key);						  // find_path_value
void ft_free_str(char **str);						  // ft_free_str
int exp_check(char *str);							  // exp_check
int ft_line_check(char *line);						  //
void export_env();
void env(); // env

// mem_wide
char **mem_wide(char **arr, int size);
void *ft_realloc(void *ptr, size_t size);

// burda kaldım
char *ft_new_left_str(char *left_str);
char *ft_search_n_str(int fd, char *left_str);
char *ft_get_one_line(char *left_str);
void *ft_realloc(void *ptr, size_t size);
// char *get_next_line(int fd);
char *dolar_sp(char *arr);
char *env_find_value(char *key);
char *my_strtok(char *str, char *delim);
char *eq_cut(char *s1);
int exp_env_check(char *str);
int line_check(char *line);
void dq_loop(char **args);
int lsh_help(char **args); // hiç kullanılmamış
void line_write(char *line);

// signal
void ctrl_d(void);
void ctrl_c(int sig);
void sig_handler(int sig_num);
void sig_handler_heredoc(int sig_num);

int ft_argslen(char **args);
// dir
int redirect_out(char **str, int i);
int redirect_in(char **str, int i);
int check_dir(char **str);
void redir2_in_handle(char **str, int i, char **s);
void here_doc(char *file, char *eof);
void ft_putstrendl_fd(char *s, int fd);
void redir2_out_handle(char **str, int i, char **s);
void exec_fork(char **s, int fd, int i);

// pipes
void	pipe_handle(char *str, int n_pipe);



//free
void	ft_lst_free(t_list **stackA);
void	run_signals(int sig);
//echo_utils
void print_double_quote(char **arr, int *i);
void print_single_quote(char **arr, int *i);
void print_mixed_quote(char **arr, int *i);
//command_utils
char *add_space();
char *handle_end_of_string(char *str, int j, int i);
char *handle_double_quotes(char *str, int j, int *i,char *tmp);
char *handle_single_quotes(char *str, int j, int *i,char *tmp);
char *handle_dollar_sign(char *str, int j, int *i);
char *handle_other_cases(char *str, int j, int *i);
#endif