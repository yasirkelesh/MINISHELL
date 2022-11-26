/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/29 12:01:37 by mukeles          ###   ########.fr       */
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

void init(t_builtin_str *str);
int line_check(char *line);
int lsh_launch(char **args, t_builtin_str *str);
int lsh_execute(char **args, t_builtin_str *str);
void *ft_realloc(void *ptr, size_t size);
void dq_loop(char **args);
char *dolar_sp(char *arr);

char **lsh_split_line(char *line);
char **ft_split(char const *s, char c);
char *my_strtok(char *str, char *delim);
int lsh_num_builtins(t_builtin_str *str, char *args);
void lsh_cd(char **arr);
void env();
int lsh_help(char **args);
void export(char **args);
int lsh_exit(char **args);
void pwd();
void echo(char **arr);
void line_write(char *line);
void ft_lstadd_back(t_list **lst, t_list *new);

t_list *ft_lstnew(void *content);
t_list *get_new_env(char **env);
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 500
#endif

char *get_next_line(int fd);
char *ft_new_left_str(char *left_str);
char *ft_search_n_str(int fd, char *left_str);
char *ft_get_one_line(char *left_str);

size_t ft_strlen(const char *str);
char *ft_strchr(const char *str, int ch);
char *ft_strjoin(char *s1, char *s2);
int ft_lstsize(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdellone(t_list **lst, t_list *dell);
void ft_list_remove_if(t_list **begin_list, void *data_ref);

int check_valid(char *str);
int get_cmd_num(const char *str);
char *command(char *str, int *i);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *parser(char *str);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *dollar(char *str, int *i);
char *get_value(char *key);
char *double_quotes(char *str, int *i);
char *slash(char *str, int *i);
char *quotes(char *str, int *i);
int ft_isalnum(int str);
void unset(char **args);
int exp_check(char *str);
int ft_strcmp(char *s1, char *s2);
char *eq_cut(char *s1);
char **ft_split(char const *s, char c);
char* replaceWord(const char* s, const char* oldW, const char* newW);
char *q_dollar(char *tmp);
// signal
void ctrl_d(void);
void ctrl_c(int sig);
void sig_handler(int sig_num);
void sig_handler_heredoc(int sig_num);

#endif
