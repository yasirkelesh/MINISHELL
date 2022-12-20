#include "mini_shell.h"

int ft_line_check(char *line)
{
    int i = 0;
    int len;
    len = ft_strlen(line);
    if (line[0] == '\0')
        return 0;
    while (line[i] <= 32 && line[i])
    {
        i++;
    }
    if (len == i)
        return 0;
    return 1;
}