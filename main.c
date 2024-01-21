#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
    char *str = malloc(10);
    char *ptr;


    ptr = str;
    str = ft_strjoin(str, "hello");
    free(ptr);
    free(str);
    return 0;
}
