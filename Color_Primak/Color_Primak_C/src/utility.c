#include "../headers/utility.h"

float f_max(float x, float y, float z)
{
    float m = x;
    m = y > m ? y : m;
    m = z > m ? z : m;
    return m;
}

float f_min(float x, float y, float z)
{
    float m = x;
    m = y < m ? y : m;
    m = z < m ? z : m;
    return m;
}

int f_eq(float x, float y)
{
    if (fabs(x-y) < 0.001f)
        return 1;
    else
        return 0;
}
