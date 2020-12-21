#ifndef COLORCMYK_H_INCLUDED
#define COLORCMYK_H_INCLUDED

#include <stdio.h>

typedef struct
{
    float cyan;
    float magenta;
    float yellow;
    float key;
} colorcmyk;

colorcmyk scanColorCMYK(float c, float m, float y, float k); //Color inputing

void printColorCMYK(colorcmyk cmyk);                         //Color outputting

colorcmyk plusCMYK(colorcmyk cmyk1, colorcmyk cmyk2);        //Adding two colors

colorcmyk CMYKtoCMYK(colorcmyk cmyk);                        //Convert from CMYK to CMYK

#include "colorrgba.h"
colorrgba CMYKtoRGBA(colorcmyk cmyk);                        //Convert from CMYK to RGBA

#include "colorhsb.h"
colorhsb CMYKtoHSB(colorcmyk cmyk);                          //Convert from CMYK to HSB

#endif // COLORCMYK_H_INCLUDED
