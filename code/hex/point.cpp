#ifndef POINT_CPP
#define POINT_CPP 1
#endif

#ifndef _GLIBCXX_TR1_MATH_H
#include <math.h>
#endif

#include "point.h"

Point::Point()
{
    //
}

/**
 * @author jason
 * 
 */
int Point::changeTo(COLOR c)
{
    if (color != WHITE)
        return -1;
    else
    {
        color = c;
        return 0;
    }
}

double Point::getPotential()
{
    return sqrt(p[0] * distance[0] + p[1] * distance[1]);
}