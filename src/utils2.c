#include "fdf.h"

int assign_if_int(int cond, int c1, int c2)
{
    if (cond)
        return (c1);
    else
        return (c2);
}

float   assign_if_float(int cond, float c1, float c2)
{
    if (cond)
        return (c1);
    else
        return (c2);
}