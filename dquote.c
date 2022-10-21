/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:27:48 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/21 14:06:20 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int line_check(char *line)
{
    int i = 0;
    int nail = 0;
    /* printf("test"); */
    while (line[i])
    {
        if (line[i] == '"')
            nail++;
        i++;
    }
    if (nail % 2 == 0)
        return 1;
    return 0;
}
void dq_loop(char *arg)
{
    char *newline;
    char **args;
    if (!strcmp(arg, "echo"))
    {
        while (1)
        {
            newline = readline("dquote> ");
            if (line_check(newline))
            {
                args = lsh_split_line(newline);
            }
            else
            {
                args = lsh_split_line(newline);
                echo(args);
                break;
            }
        }
    }
    else
    {
        while (1)
        {
            // printf("test");
            newline = readline("dquote> ");
            if (!line_check(newline))
                break;
        }
        // perror("error");
    }
}