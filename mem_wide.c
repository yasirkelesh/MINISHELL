#include "mini_shell.h"

void *ft_realloc(void *ptr, size_t size)
{
    void *new_data = NULL;

    if (size)
    {
        if (!ptr)
        {
            return malloc(size);
        }

        new_data = malloc(size);
        if (new_data)
        {
            memcpy(new_data, ptr, size); // TODO: unsafe copy...
            free(ptr);                   // we always move the data. free.
        }
    }

    return new_data;
}