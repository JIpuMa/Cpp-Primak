#include "colorhsb.h"
#include "colorrgba.h"
#include "colorcmyk.h"

#include <math.h>
#include "utility.h"

unsigned short ColorHSB::Hue() const
{
    return hue;
}

void ColorHSB::setHue(unsigned short h)
{
    hue = h;
}

float ColorHSB::Saturation() const
{
    return saturation;
}

void ColorHSB::setSaturation(float s)
{
    saturation = s;
}

float ColorHSB::Brightness() const
{
    return brightness;
}

void ColorHSB::setBrightness(float b)
{
    brightness = b;
}

ColorRGBA ColorHSB::toRGBA()
{
    float c = brightness * saturation;
    float h = hue/60.0f;
    h = fmodf(h,2) - 1.0f;
    float x = c * (1.0f - fabsf(h));
    float m = brightness - c;
    float r = 0, g = 0, b = 0;
    if(hue< 60)
    {
        r = c;
        g = x;
    }
    else if (hue >= 60 && hue < 120)
    {
        r = x;
        g = c;
    }
    else if (hue >= 120 && hue < 180)
    {
        g = c;
        b = x;
    }
    else if (hue >= 180 && hue < 240)
    {
        g = x;
        b = c;
    }
    else if (hue >= 240 && hue < 300)
    {
        r = x;
        b = c;
    }
    else
    {
        r = c;
        b = x;
    }
    unsigned short R = static_cast<unsigned short>((r+m)*255.0f);
    unsigned short G = static_cast<unsigned short>((g+m)*255.0f);
    unsigned short B = static_cast<unsigned short>((b+m)*255.0f);
    return ColorRGBA(R,G,B);
}

ColorCMYK ColorHSB::toCMYK()
{
    return this->toRGBA().toCMYK();
}

ColorHSB ColorHSB::toHSB()
{
    return *this;
}

ColorHSB operator+(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorHSB((clr1.hue + clr2.hue)/2,(clr1.saturation + clr2.saturation)/2,(clr1.brightness + clr2.brightness)/2);
}

ColorHSB operator&(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorRGBA(int(clr1) & int(clr2)).toHSB();
}

ColorHSB operator|(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorRGBA(int(clr1) | int(clr2)).toHSB();
}

ColorHSB operator^(ColorHSB &clr1, ColorHSB &clr2)
{
    return ColorRGBA(int(clr1) ^ int(clr2)).toHSB();
}

ColorHSB::operator float()
{
    return static_cast<float>(int(*this));
}

ColorHSB::operator int()
{
    return int(this->toRGBA());
}

void ColorHSB::printColor()
{
    std::cout  << hue << " " << saturation << " " << brightness << std::endl;
}

void ColorHSB::printColorInt()
{
    std::cout << int(*this) << std::endl;
}

void ColorHSB::printColorFloat()
{
    std::cout << float(*this) << std::endl;
}

ColorHSB::ColorHSB(unsigned short h, float s, float b) : hue(h > 360 ? 360 : h), saturation(s > 1 ? 1 : s), brightness(b > 1 ? 1 : b)
{

}

