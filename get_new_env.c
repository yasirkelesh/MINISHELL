#include "mini_shell.h"
//halloldu
t_list *get_new_env(char **env)
{
	t_list *new_env;
	int i;

	new_env = malloc(sizeof(t_list));
	i = 0;
	while(env[i])
	{
		ft_lstadd_back(&new_env, ft_lstnew(env[i]));
		i++;
	}
	return (new_env);
}