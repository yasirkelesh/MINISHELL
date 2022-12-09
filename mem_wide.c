#include "mini_shell.h"

char **mem_wide(char **arr, int size)
{
    char **tmp;
    tmp = malloc(sizeof(char *) * (size * 2));

    int i = 0;
    while (arr[i])
    {
        tmp[i] = arr[i];
        i++;
    }
    free(arr);
    return (tmp);
    
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