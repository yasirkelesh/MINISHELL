#include "mini_shell.h"

int exp_env_check(char *str)
{
    t_list *tmp;
    char   **args;
    printf("test\n");
    tmp = g_env;
    tmp = tmp->next;
    if(str == NULL)
        return 0;
    while(tmp)
    {
        args = ft_split(tmp->content, '=');
/*         printf("args[i] %s\n",args[1]);
        printf("str %s\n",str); */
        if(ft_strcmp(args[1],str) &&  (ft_strlen(args[1]) == ft_strlen(str)))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}