/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:40:07 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/04 17:15:42 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINI_SHELL_H
# define MINI_SHELL_H

#define EXIT_FAILURE
#define LSH_TOK_BUFSIZE 999
#define LSH_TOK_DELIM " \t\r\n\a"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>



void sh_loop(void);
char	**ft_split(char const *s, char c);
char *strtok(char *str, const char *delim);

#endif
