#include "mini_shell.h"
void print_double_quote(char **arr, int *i)
{
    int k = 0;
    int len;
    char *tmp;
    len = ft_strlen(arr[(*i)]);
    arr[(*i)] = ft_substr(arr[(*i)], 1, len - 2);
    while (arr[(*i)][k] && arr[(*i)])
    {
        if (arr[(*i)][k] != '$' && arr[(*i)][k] != '\'' && arr[(*i)][k] != '\"')
        {
            printf("%c", arr[(*i)][k]);
            k++;
        }
        else if (arr[(*i)][k] == '$')
        {
            while (ft_isalnum(arr[(*i)][k]) != 0 && arr[(*i)])
                k++;
            tmp = dollar(arr[(*i)], &k);
            if (tmp)
                printf("%s", tmp);
        }
    }
    (*i)++;
}
void print_single_quote(char **arr, int *i)
{
    int len;
    len = ft_strlen(arr[(*i)]);
    arr[(*i)] = ft_substr(arr[(*i)], 1, len - 2);
    if (arr[(*i)])
        printf("%s", arr[(*i)]);
    (*i)++;
}
void print_mixed_quote(char **arr, int *i)
{
    int k = 0;
    char *tmp;
    int len;
    if (arr[(*i)][k] == '\"')
    {
        k++;
        while (arr[(*i)][k])
        {
            if (arr[(*i)][k] != '$' && arr[(*i)][k] != '\"')
            {
                printf("%c", arr[(*i)][k]);
                k++;
            }
            else if (arr[(*i)][k] == '$')
            {
                while (ft_isalnum(arr[(*i)][k]) != 0 && arr[(*i)])
                    k++;
                tmp = dollar(arr[(*i)], &k);
                if (tmp)
                    printf("%s", tmp);
            }
            else
            {
                k++;
            }
        }
        (*i)++;
    }
    else if (arr[(*i)][k] == '\'')
    {
        len = ft_strlen(arr[(*i)]);
        arr[(*i)] = ft_substr(arr[(*i)], 1, len - 2);
        if (arr[(*i)])
            printf("%s", arr[(*i)]);
        (*i)++;
    }
}