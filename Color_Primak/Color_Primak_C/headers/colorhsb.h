#ifndef COLORHSB_H_INCLUDED
#define COLORHSB_H_INCLUDED

#include <stdio.h>

typedef struct
{
    unsigned hue;
    float saturation;
    float brightness;
} colorhsb;

colorhsb scanColorHSB(unsigned h, float s, float b);

void printColorHSB(colorhsb hsb);

colorhsb plusHSB(colorhsb hsb1, colorhsb hsb2);

colorhsb HSBtoHSB(colorhsb hsb);

#include "colorrgba.h"
colorrgba HSBtoRGBA(colorhsb hsb);

#include "colorcmyk.h"
colorcmyk HSBtoCMYK(colorhsb hsb);

#endif // COLORHSB_H_INCLUDED
