#ifndef COLORRGBA_H_INCLUDED
#define COLORRGBA_H_INCLUDED

#include <stdio.h>

#include "utility.h"

typedef struct
{
    unsigned short red;       //Value of red
    unsigned short green;     //Value of green
    unsigned short blue;      //Value of blue
    unsigned short alpha;     //Value of alpha
} colorrgba;

colorrgba scanColorRGBA(unsigned short r, unsigned short g, unsigned short b, unsigned short a);   //Color inputing

void printColorRGBA(colorrgba rgba);                      //Color outputting

colorrgba plusRGBA(colorrgba rgba1, colorrgba rgba2);     //Adding two colors

colorrgba RGBAtoRGBA(colorrgba rgba);                     //Convert from RGBA to RGBA

#include "colorcmyk.h"
colorcmyk RGBAtoCMYK(colorrgba rgba);                     //Convert from RGBA to CMYK

#include "colorhsb.h"
colorhsb RGBAtoHSB(colorrgba rgba);                       //Convert from RGBA to HSB

#endif // COLORRGBA_H_INCLUDED
