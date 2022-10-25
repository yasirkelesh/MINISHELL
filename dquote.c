/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:27:48 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/25 23:13:12 by mukeles          ###   ########.fr       */
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
void dq_loop(char **args)
{
    char *newline;
    int fd;
    if (!strcmp(args[0], "echo"))
    {
        while (1)
        {
            newline = readline("dquote> ");
            // printf("test");
            if (line_check(newline))
            {
                line_write(newline);
            }
            else
            {
                
                line_write(newline);
                fd = open("yasir.txt", O_RDWR, 0777);
                get_next_line(fd);
                close(fd);
                fd = open("yasir.txt", O_TRUNC, 0777);
                close(fd);
                break;
            }
        }
    }
    else
    {
        while (1)
        {

            newline = readline("dquote> ");
            if (!line_check(newline))
                break;
        }
        // perror("error");
    }
}