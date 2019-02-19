#ifndef POINT_H
#define POINT_H 1

#ifndef COLOR_H
#include "color.h"
#endif

class Point
{
  public:
    COLOR color = WHITE;
    double distance[2];
    int p[2];

    Point();
    
    int changeTo(COLOR c);
    double getPotential();
    void calcPotential();
};

#endif