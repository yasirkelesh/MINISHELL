#include "mini_shell.h"
// halloldu
char *command(char *str, int *i)
{
    int j;
    char *tmp=0;
    j = *i;
    while (str[*i])
    {
        while (str[*i] == ' ' && str[*i] != '\0')
            i++;
        if (*i == 0)
        {
            //printf("test1\n");
            while (str[*i] != ' ' && str[*i] != '\0')
                (*i)++;
            tmp = ft_substr(str, j, *i - j);
            return tmp;
        }
        if (str[*i] == '$')
        {
            (*i)++;
            while (ft_isalnum(str[*i]) && str[*i] != '\0')
                (*i)++;
            tmp = ft_substr(str, j, *i - j);

            return tmp;
        }

        if (str[*i] == '\"')
        {
            (*i)++;
            if (str[*i] != '\"')
            {
                while (str[*i] != '\"' && str[*i] != '\0')
                    (*i)++;
                (*i)++;
                tmp = ft_substr(str, j, *i - (j));
            }
            else
                tmp = ft_substr(str, j, *i - (j + 1));
            return tmp;
        }
        if (str[*i] == '\'' && str[*i])
        {
            (*i)++;
            if (str[*i] != '\'')
            {
                while (str[*i] != '\'' && str[*i] != '\0')
                    (*i)++;
                (*i)++;
                tmp = ft_substr(str, j, *i - (j));
            }
            else
                tmp = ft_substr(str, j, *i - (j + 1));

            return tmp;
        }

        else
        {
            while (str[*i] != ' ' && str[*i] != '\'' && str[*i] != '\"' && str[*i] != '\0')
                (*i)++;
            tmp = ft_substr(str, j, *i - (j));
            return tmp;
        }
    }
    return tmp;
}