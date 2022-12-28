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

void echo(char **arr)
{

    int size;

    int i;
    int n;


    usleep(1000);
    size = 0;
    n = 0;
    while (arr[size])
    {
        size++;
    }
    i = 1;
    while (ft_strncmp(arr[i], "-n", 3) == 0)
    {
        n = 1;
        i++;
    }
    if(!ft_strcmp(arr[i], " "))
        i++;

    while (arr[i])
    {
        if (ft_strrchr(arr[i], '\'') == 0 && ft_strrchr(arr[i], '\"') == 0)
        {
            printf("%s", arr[i]);
            /* if (i != size - 1)
                printf(" "); */
            i++;
        }
        else if (ft_strrchr(arr[i], '\'') == 0 && ft_strrchr(arr[i], '\"') != 0)
        {
            print_double_quote(arr, &i);
        }
        else if (ft_strrchr(arr[i], '\'') != 0 && ft_strrchr(arr[i], '\"') == 0)
        {
            print_single_quote(arr, &i);
        }
        else if (ft_strrchr(arr[i], '\'') != 0 && ft_strrchr(arr[i], '\"') != 0)
        {
             print_mixed_quote(arr, &i);
        }
    }
    if (arr[1] == NULL)
        printf("\n");
    if (!n)
        printf("\n");
}