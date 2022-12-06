/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2022/12/02 16:31:34 by mukeles          ###   ########.fr       */
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

#define EXIT_SYNTAX_ERROR 258
#define EXIT_CMD_NOT_FOUND 127
#define EXIT_CTRL_D 130

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

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

t_list *ft_lstnew(void *content);
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 500
#endif

//libft
size_t ft_strlen(const char *str);
char   **ft_split(char const *s, char c);
char   *ft_strchr(const char *str, int ch);
char   *ft_strjoin(char *s1, char *s2);
char   *ft_substr(char const *s, unsigned int start, size_t len);
char   *ft_strdup(char *str);
int    ft_strncmp(const char *s1, const char *s2, size_t n);
int    ft_isalnum(int str);
int    ft_strcmp(char *s1, char *s2);
int    ft_lstsize(t_list *lst);
void   ft_lstadd_back(t_list **lst, t_list *new);
void   ft_lstdellone(t_list **lst, t_list *dell);
void   ft_lstadd_back(t_list **lst, t_list *new);
void   ft_list_remove_if(t_list **begin_list, void *data_ref);
//lsh_loop
void lsh_loop(t_builtin_str *str);
//lsh_launch
int lsh_launch(char **args, t_builtin_str *str);
//lsh_split_line
char **lsh_split_line(char *line);
//init
void init(t_builtin_str *str);
//get_new_env
t_list *get_new_env(char **env);
//lsh_loop
void lsh_loop(t_builtin_str *str);
//lsh_split_line
char **lsh_split_line(char *line);
//get_cmd_num
int get_cmd_num(const char *str);
//command
char *command(char *str, int *i);
//q_dollar
char *q_dollar(char *tmp);
//dollar_query
int dollar_query(char *tmp);
//dollar
char *dollar(char *str, int *i);
char *get_value(char *key);
//replaceWord
char* replaceWord(const char* s, const char* oldW,const char* newW);
//check_valid
int check_valid(char *line);
//parser
char *parser(char *str);
//double_quetes
char *double_quotes(char *str, int *i);
//slash
char *slash(char *str, int *i);
//quotes
char *quotes(char *str, int *i);
//get_value
char *get_value(char *key);
//cd_exit_execute
void lsh_cd(char **arr);
int  lsh_exit(char **args);
int  lsh_execute(char **args, t_builtin_str *str);
int  lsh_num_builtins(t_builtin_str *str, char *args);
//echo_pwd_env_export_unset
void export(char **args);
void pwd();
void echo(char **arr);
void unset(char **args);
//lsh_launch
int lsh_launch(char **args, t_builtin_str *str);
//find_path_value
char *find_path(char *cmdline);
char *find_value(char *key);
//ft_free_str
void ft_free_str(char **str);
//exp_check
int exp_check(char *str);
//env
void env();

//burda kaldım
char *ft_new_left_str(char *left_str);
char *ft_search_n_str(int fd, char *left_str);
char *ft_get_one_line(char *left_str);
void *ft_realloc(void *ptr, size_t size);
char *get_next_line(int fd);
char *dolar_sp(char *arr);
char *env_find_value(char *key);
char *my_strtok(char *str, char *delim);
char *eq_cut(char *s1);
int  exp_env_check(char *str);
int  line_check(char *line);
void dq_loop(char **args);
int  lsh_help(char **args);//hiç kullanılmamış
void line_write(char *line);


// signal
void ctrl_d(void);
void ctrl_c(int sig);
void sig_handler(int sig_num);
void sig_handler_heredoc(int sig_num);

#endif
