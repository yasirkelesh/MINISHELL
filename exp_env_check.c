#include "mini_shell.h"

int exp_env_check(char *str)
{
    t_list *tmp;
    char **args;
    printf("test\n");
    tmp = g_env;
    tmp = tmp->next;
    if (str == NULL)
        return 0;
    while (tmp)
    {
        args = ft_split(tmp->content, '=');
                printf("args[i] %s\n",args[1]);
                printf("str %s\n",str);
                printf("ft_strcmp : %d\n",ft_strcmp(args[1],str));
                printf("ft_strlen(args[1]) : %d\n",ft_strlen(args[1]));
                printf("ft_strlen(str) : %d\n",ft_strlen(str));

        if (args[1] != NULL)
        {
            if (ft_strcmp(args[1], str) == 0 && (ft_strlen(args[1]) == ft_strlen(str)))
                return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}