#include "header.h"


int     splitArray(struct s_art **arts, int start, int end)
{
    int     pivot;

    pivot = end / 2;
    while (start < pivot)
    {
        
    }


}

void    quicksort(struct s_art **arts, int start, int end)
{
    int     pivot;

    if (start >= end)
        return ;

    pivot = splitArray(arts, start, end);
    quickSort(arts, start, pivot - 1);
    quickSort(arts, pivot + 1, end);
}

void    sortArts(struct s_art **arts)
{
    quickSort(arts, 0, sizeof(arts) / sizeof(arts[0]));
}
