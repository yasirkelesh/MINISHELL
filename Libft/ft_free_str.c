#include "libft.h"
//halloldu
void	ft_free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	
}
void	ft_lst_free(t_list **stackA)
{
	t_list	*temp;

	temp = NULL;
	while (*stackA)
	{
		temp = (*stackA)->next;
		free(*stackA);
		*stackA = NULL;
		if (temp == NULL)
			break ;
		*stackA = temp;
	}
	free(stackA);
}