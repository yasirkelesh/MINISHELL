/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/11 21:07:07 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINI_SHELL_H
# define MINI_SHELL_H

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \'\"\t\r\n\a"

#define DICT_LEN 256
extern char **environ;

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>



int lsh_launch(char **args);
int lsh_execute(char **args);
void* ft_realloc(void* ptr, size_t size);
char	**ft_split(char const *s, char c);
char *my_strtok(char *str,  char *delim);
int lsh_num_builtins();
void lsh_cd(char **arr);
int lsh_help(char **args);
int lsh_exit(char **args);
void pwd();
void echo(char **arr);

#endif
