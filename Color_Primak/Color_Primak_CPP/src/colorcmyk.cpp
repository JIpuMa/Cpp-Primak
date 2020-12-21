#include "colorcmyk.h"
#include "colorhsb.h"
#include "colorrgba.h"

float ColorCMYK::Cyan() const
{
    return cyan;
}

void ColorCMYK::setCyan(float c)
{
    cyan = c;
}

float ColorCMYK::Magenta() const
{
    return magenta;
}

void ColorCMYK::setMagenta(char m)
{
    magenta = m;
}

float ColorCMYK::Yellow() const
{
    return yellow;
}

void ColorCMYK::setYellow(float y)
{
    yellow = y;
}

float ColorCMYK::Key() const
{
    return key;
}

void ColorCMYK::setKey(float k)
{
    key = k;
}

ColorRGBA ColorCMYK::toRGBA()
{
    char r = char(255 * (1-cyan) * (1-key));
    char g = char(255 * (1-magenta) * (1-key));
    char b = char(255 * (1-yellow) * (1-key));
    return ColorRGBA(r,g,b);
}

ColorCMYK ColorCMYK::toCMYK()
{
    return *this;
}

ColorHSB ColorCMYK::toHSB()
{
    return this->toRGBA().toHSB();
}

ColorCMYK operator+(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorCMYK((clr1.cyan + clr2.cyan)/2,(clr1.magenta + clr2.magenta)/2,(clr1.yellow + clr2.yellow)/2,(clr1.key + clr2.key)/2);
}

ColorCMYK operator&(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorRGBA(int(clr1) & int(clr2)).toCMYK();
}

ColorCMYK operator|(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorRGBA(int(clr1) | int(clr2)).toCMYK();
}

ColorCMYK operator^(ColorCMYK &clr1, ColorCMYK &clr2)
{
    return ColorRGBA(int(clr1) ^ int(clr2)).toCMYK();
}

ColorCMYK::operator float()
{
    return static_cast<float>(int(*this));
}

ColorCMYK::operator int()
{
    return int(this->toRGBA());
}

void ColorCMYK::printColor()
{
    std::cout << cyan << " " << magenta << " " << yellow << " " << key << std::endl;
}

void ColorCMYK::printColorInt()
{
    std::cout << int(*this) << std::endl;
}

void ColorCMYK::printColorFloat()
{
    std::cout << float(*this) << std::endl;
}

ColorCMYK::ColorCMYK(float c, float m, float y, float k) : cyan(c > 1 ? 1 : c), magenta(m > 1 ? 1 : m), yellow(y > 1 ? 1 : y), key(k > 1 ? 1 : k)
{

}
