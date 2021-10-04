#include "fdf.h"

int assign_if_int(int cond, int c1, int c2)
{
    if (cond)
        return (c1);
    else
        return (c2);
}