#include "mini_shell.h"

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
    if (!ft_strcmp(arr[i], " "))
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