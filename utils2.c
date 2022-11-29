
#include "mini_shell.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}
char	*ft_strdup(char *str)
{
	size_t	i;
	char	*p1;
	size_t	index;

	index = 0;
	i = ft_strlen(str);
	p1 = malloc(sizeof(char) * (i + 1));
	if (!p1)
		return (NULL);
	while (str[index])
	{
		p1[index] = str[index];
		index++;
	}
	p1[index] = '\0';
	return (p1);
}

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