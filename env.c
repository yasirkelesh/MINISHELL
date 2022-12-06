#include "mini_shell.h"

void env()
{
	t_list *tmp;

	tmp = g_env;
    tmp = tmp->next;
	while(tmp)
	{
		printf("%s\n", (char*)tmp->content);
		tmp = tmp->next;
	}
}