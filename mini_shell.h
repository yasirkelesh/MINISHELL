/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalyonc <nkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2022/12/09 10:49:54 by nkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \"\t\r\n\a"

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

typedef struct s_list
{
	void *content;
	struct s_list *next;
} b_list;

t_list *g_env;
typedef struct shelldup
{
	int std_in;
	int std_out;
	int f_in;
	int f_out;

} shelldup;

typedef struct s_builtin_str
{
	char **builtin_str;

} t_builtin_str;


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 500
#endif


void lsh_loop(t_builtin_str *str);// lsh_loop
int lsh_launch(char **args, t_builtin_str *str);// lsh_launch
char **lsh_split_line(char *line);// lsh_split_line
void init(t_builtin_str *str);// init
t_list *get_new_env(char **env);// get_new_env
void lsh_loop(t_builtin_str *str);// lsh_loop
char **lsh_split_line(char *line);// lsh_split_line
int get_cmd_num(const char *str);// get_cmd_num
char *command(char *str, int *i);// command
char *q_dollar(char *tmp);// q_dollar
int dollar_query(char *tmp);// dollar_query
char *dollar(char *str, int *i);// dollar
char *get_value(char *key);// dollar
char *replaceWord(const char *s, const char *oldW, const char *newW);// replaceWord
int check_valid(char *line);// check_valid
char *parser(char *str);// parser
char *double_quotes(char *str, int *i);// double_quetes
char *slash(char *str, int *i);// slash
char *quotes(char *str, int *i);// quotes
char *get_value(char *key);// get_value
void lsh_cd(char **arr);// cd_exit_execute
int lsh_exit(char **args);// cd_exit_execute
int lsh_execute(char **args, t_builtin_str *str);// cd_exit_execute
int lsh_num_builtins(t_builtin_str *str, char *args);// cd_exit_execute
void export(char **args);// echo_pwd_env_export_unset
void pwd();// echo_pwd_env_export_unset
void echo(char **arr);// echo_pwd_env_export_unset
void unset(char **args);// echo_pwd_env_export_unset
int lsh_launch(char **args, t_builtin_str *str);// lsh_launch
char *find_path(char *cmdline);// find_path_value
char *find_value(char *key);// find_path_value
void ft_free_str(char **str);// ft_free_str
int exp_check(char *str);// exp_check
void env();// env

// burda kaldım
char *ft_new_left_str(char *left_str);
char *ft_search_n_str(int fd, char *left_str);
char *ft_get_one_line(char *left_str);
void *ft_realloc(void *ptr, size_t size);
//char *get_next_line(int fd);
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

#endif