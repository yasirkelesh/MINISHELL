#include "mini_shell.h"

void line_write(char *line)
{
    int fd;
    
    fd = open("yasir.txt", O_APPEND | O_CREAT | O_RDWR, 0777);

    write(fd, line, strlen(line));
    write(fd, "\n", 1);
    close(fd);

 
}