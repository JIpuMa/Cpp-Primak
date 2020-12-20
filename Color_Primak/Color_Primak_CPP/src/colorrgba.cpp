#include "colorrgba.h"
#include "colorcmyk.h"
#include "colorhsb.h"
#include "utility.h"

unsigned short ColorRGBA::Red() const
{
    return red;
}

void ColorRGBA::setRed(TUS r)
{
    red = r;
}

unsigned short ColorRGBA::Green() const
{
    return green;
}

void ColorRGBA::setGreen(TUS g)
{
    green = g;
}

unsigned short ColorRGBA::Blue() const
{
    return blue;
}

void ColorRGBA::setBlue(TUS b)
{
    blue = b;
}

unsigned short ColorRGBA::Alpha() const
{
    return alpha;
}

void ColorRGBA::setAlpha(TUS a)
{
    alpha = a;
}

ColorRGBA ColorRGBA::toRGBA()
{
    return *this;
}

ColorCMYK ColorRGBA::toCMYK()
{
    float r = (red * alpha/255.0f)/255;
    float g = (green * alpha/255.0f)/255;
    float b = (blue * alpha/255.0f)/255;
    float k = r;
    k = f_max(r,g,b);
    k = 1 - k;
    if(k == 1.0f)
    {
        return ColorCMYK{0,0,0,1};
    }
    float c = (1-r-k)/(1-k);
    float m = (1-g-k)/(1-k);
    float y = (1-b-k)/(1-k);
    return ColorCMYK(c,m,y,k);
}

ColorHSB ColorRGBA::toHSB()
{
    float r = (red * alpha/255.0f)/255;
    float g = (green * alpha/255.0f)/255;
    float b = (blue * alpha/255.0f)/255;
    float max_c = f_max(r,g,b), min_c = f_min(r,g,b);
    float delta = max_c - min_c;
    float bri = max_c;
    float hue = 0;
    if(f_eq(delta,0.0f))
    {
        return ColorHSB(0,0,bri);
    }
    else if (f_eq(max_c,r))
    {
        hue = (g-b)/delta;
    }
    else if (f_eq(max_c,g))
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
    float sat = f_eq(delta,0.0f) ? 0 : (delta/max_c);
    return ColorHSB(static_cast<unsigned short>(hue),sat,bri);
}

ColorRGBA operator^(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA(int(clr1) ^ int(clr2));
}

ColorRGBA operator|(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA(int(clr1) | int(clr2));
}

ColorRGBA operator&(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA(int(clr1) & int(clr2));
}

ColorRGBA operator+(ColorRGBA &clr1, ColorRGBA &clr2)
{
    return ColorRGBA((clr1.red + clr2.red)/2,(clr1.green + clr2.green)/2,(clr1.blue + clr2.blue)/2,(clr1.alpha + clr2.alpha)/2);
}

ColorRGBA::operator float()
{
    return static_cast<float>(int(*this));
}

ColorRGBA::operator int()
{
    return 0 | (red << 24) | (green << 16) | (blue << 8) | (alpha);
}

void ColorRGBA::printColor()
{
    std::cout << red << " " << green << " " << blue << " " << alpha << std::endl;
}

void ColorRGBA::printColorInt()
{
    std::cout << int(*this) << std::endl;
}

void ColorRGBA::printColorFloat()
{
    std::cout << float(*this) << std::endl;
}

ColorRGBA::ColorRGBA(TUS r, TUS g, TUS b, TUS a) : red(r > 255 ? 255 : r), green(g > 255 ? 255 : g), blue(b > 255 ? 255 : b), alpha(a > 255 ? 255 : a)
{

}

ColorRGBA::ColorRGBA(int val) : red((val >> 24) & 255), green((val >> 16) & 255), blue((val >> 8) & 255), alpha(val & 255)
{

}
