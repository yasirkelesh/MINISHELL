#include "mini_shell.h"

void echo(char **arr)
{

    int size;
    char *tmp;
    int i;
    int n;
    int len = 0;
    int k = 0;
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
    while (arr[i])
    {
        if (ft_strrchr(arr[i], '\'') == 0 && ft_strrchr(arr[i], '\"') == 0)
        {
            printf("%s", arr[i]);
            if (i != size - 1)
                printf(" ");
            i++;
        }
        else if (ft_strrchr(arr[i], '\'') == 0 && ft_strrchr(arr[i], '\"') != 0)
        {
            k = 0;
            len = ft_strlen(arr[i]);
            arr[i] = ft_substr(arr[i], 1, len - 2);
            while (arr[i][k] && arr[i])
            {
                if (arr[i][k] != '$' && arr[i][k] != '\'' && arr[i][k] != '\"')
                {
                    printf("%c", arr[i][k]);
                    k++;
                }
                else if (arr[i][k] == '$')
                {
                    while (ft_isalnum(arr[i][k]) != 0 && arr[i])
                        k++;
                    tmp = dollar(arr[i], &k);
                    if (tmp)
                        printf("%s", tmp);
                }
            }
            i++;
        }
        else if (ft_strrchr(arr[i], '\'') != 0 && ft_strrchr(arr[i], '\"') == 0)
        {
            len = ft_strlen(arr[i]);
            arr[i] = ft_substr(arr[i], 1, len - 2);
            if (arr[i])
                printf("%s", arr[i]);
            i++;
        }
        else if (ft_strrchr(arr[i], '\'') != 0 && ft_strrchr(arr[i], '\"') != 0)
        {
            k = 0;
            if (arr[i][k] == '\"')
            {
                k++;
                while (arr[i][k])
                {
                    if (arr[i][k] != '$' && arr[i][k] != '\"')
                    {
                        printf("%c", arr[i][k]);
                        k++;
                    }
                    else if (arr[i][k] == '$')
                    {

                        //j = k;
                        while (ft_isalnum(arr[i][k]) != 0 && arr[i])
                            k++;
                        tmp = dollar(arr[i], &k);
                        if (tmp)
                            printf("%s", tmp);
                    }
                    else
                        k++;
                }
                i++;
            }
            else if (arr[i][k] == '\'')
            {
                len = ft_strlen(arr[i]);
                arr[i] = ft_substr(arr[i], 1, len - 2);
                if (arr[i])
                    printf("%s", arr[i]);
                i++;
            }
        }
    }
    if (!n)
        printf("\n");
}