#include "mini_shell.h"
//halloldu
void env()
{
	t_list *tmp;

	tmp = g_list.g_env;
    tmp = tmp->next;
	while(tmp)
	{
		printf("%s\n", (char*)tmp->content);
		tmp = tmp->next;
	}
}
void export_env()
{
	t_list *tmp;

	tmp = g_list.g_env;
    tmp = tmp->next;
	while(tmp)
	{
		printf("declare -x %s\n", (char*)tmp->content);
		tmp = tmp->next;
	}
}