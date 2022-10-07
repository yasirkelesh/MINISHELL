/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/07 15:35:57 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINI_SHELL_H
# define MINI_SHELL_H


#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>



char	**ft_split(char const *s, char c);
char *my_strtok(char *str,  char *delim);

#endif
