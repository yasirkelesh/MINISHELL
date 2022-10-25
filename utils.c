/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:19:46 by mukeles           #+#    #+#             */
/*   Updated: 2022/10/25 16:30:06 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;

	p = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (n--)
	{
		if (*p != *d)
			return ((int)*p - (int)*d);
		else if (!*p)
			return (0);
		p++;
		d++;
	}
	return (0);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
	{
		ans = (char*)malloc(sizeof(char) * 1);
		if (!ans)
			return (0);
	}
	else
	{
		size = ft_strlen(s) + start;
		len = size < len ? size : len;
		ans = (char*)malloc(sizeof(char) * (len + 1));
		if (!ans)
			return (0);
		while (i < len)
			ans[i++] = s[start++];
	}
	ans[i] = '\0';
	return (ans);
}

void* ft_realloc(void* ptr, size_t size)
{
	void* new_data = NULL;

	if(size)
	{
		if(!ptr)
		{
			return malloc(size);
		}

		new_data = malloc(size);
		if(new_data)
		{
			memcpy(new_data, ptr, size); // TODO: unsafe copy...
			free(ptr); // we always move the data. free.
		}
	}

	return new_data;
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	a = *lst;
	while (a->next != NULL)
		a = a->next;
	a->next = new;
}
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
