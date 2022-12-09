#include "libft.h"
void ft_list_remove_if(t_list **begin_list, void *data_ref)
{
    t_list *current;
    t_list *last;
    t_list *next;
    char **eq_env;

    current = *begin_list;
    current = current->next;
    last = ((void *)0);
    while (current)
    {
        next = current->next;
        eq_env = ft_split(current->content,'=');
        if (ft_strcmp(eq_env[0], data_ref) == 0)
        {
            if (last)
                last->next = current->next;
            else
                *begin_list = current->next;
            free(current);
            current = ((void *)0);
        }
        last = current;
        current = next;
    }
}