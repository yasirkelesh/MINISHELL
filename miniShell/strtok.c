#include "mini_shell.h"

char *strtok(char *str, const char *delim) 
{
    static char* s = NULL;
    char* tok;
    if(str == NULL) {
        if(s == NULL)
            return NULL;
        } else
    s = str;
    for(size_t i; (*s != '\0'); s++) {
        for(i = 0; (delim[i] != '\0') && (*s != delim[i]); i++);
            if(delim[i] == '\0')
                break;
    }
    if(*s == '\0')
        return s = NULL;
    tok = s++;
    for(size_t i; (*s != '\0'); s++) {
        for(i = 0; (delim[i] != '\0') && (*s != delim[i]); i++);
            if(delim[i] != '\0')
                break;
    }
        if(*s != '\0') {
            *s = '\0';
            s++;
        }
    return tok;
}