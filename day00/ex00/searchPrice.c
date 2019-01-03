#include "header.h"
#include <string.h>

int searchPrice(struct s_art **arts, char *name)
{
    int i = -1;

    if (!arts)
        return (-1);

    while (arts[++i])
    {
        if (!strcmp(arts[i]->name, name))
            return (arts[i]->price);
    }
    return (-1);
}