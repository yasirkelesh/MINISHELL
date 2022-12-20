#include "mini_shell.h"
//halloldu
char			*find_value(char *key)
{
	int	i;
    t_list *envp;
    envp =g_env;
	i = -1;
    envp = envp->next;
	while (envp->next)
	{
	if (!ft_strncmp(envp->content, key, ft_strlen(key)))
			return (envp->content + ft_strlen(key) + 1); 
        envp = envp->next;
	}
	return ("");
}

char *find_path(char *cmdline)
{
	int		i;
	char	*temp;
	char	*new_path;
	char	**paths;
	struct stat s;
	
	temp = find_value("PATH");
	paths = ft_split(temp, ':');
	i = -1;
	while(paths[++i])
	{
		temp = ft_strjoin("/", cmdline);
		new_path = ft_strjoin(paths[i], temp);
		free(temp);
		if (stat(new_path, &s) == 0)
		{
			ft_free_str(paths);
			return (new_path);
		}
		free(new_path);
	}
	ft_free_str(paths);
	return (ft_strdup(cmdline));
}