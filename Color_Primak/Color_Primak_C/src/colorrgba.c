#include "../headers/colorrgba.h"

colorrgba scanColorRGBA(unsigned short r, unsigned short g, unsigned short b, unsigned short a)
{
    colorrgba rgba;
    rgba.red = (r > 255) ? 255 : r;
    rgba.green = (g > 255) ? 255 : g;
    rgba.blue = (b > 255) ? 255 : b;
    rgba.alpha = (a > 255) ? 255 : a;
    return rgba;
}

void printColorRGBA(colorrgba rgba)
{
    printf("%d %d %d %d\n", rgba.red, rgba.green, rgba.blue, rgba.alpha);
}

colorrgba plusRGBA(colorrgba rgba1, colorrgba rgba2)
{
    colorrgba rgba;
    rgba.red = (rgba1.red + rgba2.red) / 2;
    rgba.green = (rgba1.green + rgba2.green) / 2;
    rgba.blue = (rgba1.blue + rgba2.blue) / 2;
    rgba.alpha = (rgba1.alpha + rgba2.alpha) / 2;
    return rgba;
}

colorrgba RGBAtoRGBA(colorrgba rgba)
{
    return rgba;
}

colorcmyk RGBAtoCMYK(colorrgba rgba)
{
    colorcmyk cmyk;
    float r = (rgba.red * rgba.alpha/255.0f)/255;
    float g = (rgba.green * rgba.alpha/255.0f)/255;
    float b = (rgba.blue * rgba.alpha/255.0f)/255;
    float k;
    k = f_max(r,g,b);
    k = 1 - k;
    if(k == 1.0f)
    {
        cmyk.cyan = 0;
        cmyk.magenta = 0;
        cmyk.yellow = 0;
        cmyk.key = 1;
        return cmyk;
    }
    cmyk.cyan = (1-r-k)/(1-k);
    cmyk.magenta = (1-g-k)/(1-k);
    cmyk.yellow = (1-b-k)/(1-k);
    cmyk.key = k;
    return cmyk;
}

colorhsb RGBAtoHSB(colorrgba rgba)
{
    colorhsb hsb;
    float r = (rgba.red * rgba.alpha/255.0f)/255;
    float g = (rgba.green * rgba.alpha/255.0f)/255;
    float b = (rgba.blue * rgba.alpha/255.0f)/255;
    float max_c = f_max(r,g,b), min_c = f_min(r,g,b);
    float hue = 0;
    hsb.brightness = max_c;
    float delta = max_c - min_c;
    if(f_eq(delta,0.0f) == 1)
    {
        hsb.hue = 0;
        hsb.saturation = 0;
        return hsb;
    }
    else if (f_eq(max_c,r) == 1)
    {
        hue = (g-b)/delta;
    }
    else if (f_eq(max_c,g) == 1)
    {
        hue = 2.0f + (b-r)/delta;
    }
    else
    {
        hue = 4.0f + (r-g)/delta;
    }
    hue *= 60;
    if(hue < 0.0f)
        hue += 360;
    hsb.hue = hue;
    hsb.saturation = (f_eq(delta,0.0f) == 1) ? 0 : (delta/max_c);
    return hsb;
}
