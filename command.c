#include "mini_shell.h"
// halloldu
char *command(char *str, int *i, char *args, int k)
{
    int j = *i;
    char *tmp = 0;


    if (isspace(str[*i - 1]) && strcmp(" ", args) && k != 1) // boşluk koyuyor
    {
        //printf("test\n");
        tmp = malloc(2 * sizeof(char));
        tmp[0] = ' ';
        tmp[1] = '\0';
        return tmp;
    }

    if (str[*i] == '\0')
    {
        tmp = ft_substr(str, j, *i - j);
        return tmp;
    }

    if (str[*i] == '$')
    {
        (*i)++;
        while (ft_isalnum(str[*i]) && str[*i] != '\0')
        {
            (*i)++;
        }
        tmp = ft_substr(str, j, *i - j);
        return tmp;
    }

    if (str[*i] == '\"')
    {
        (*i)++;
        if (str[*i] != '\"')
        {
            while (str[*i] != '\"' && str[*i] != '\0')
            {
                (*i)++;
            }
            (*i)++;
            tmp = ft_substr(str, j, *i - (j));
        }
        else
        {
            tmp = ft_substr(str, j, *i - (j + 1));
        }
        return tmp;
    }

    if (str[*i] == '\'' && str[*i])
    {
        (*i)++;
        if (str[*i] != '\'')
        {
            while (str[*i] != '\'' && str[*i] != '\0')
            {
                (*i)++;
            }
            (*i)++;
            tmp = ft_substr(str, j, *i - (j));
        }
        else
        {
            tmp = ft_substr(str, j, *i - (j + 1));
        }
        return tmp;
    }
    while (str[*i] != ' ' && str[*i] != '\'' && str[*i] != '\"' && str[*i] != '\0')
    {
        (*i)++;
    }
    tmp = ft_substr(str, j, *i - (j));
    return tmp;
}