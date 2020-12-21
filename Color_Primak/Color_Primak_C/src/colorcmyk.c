#include "../headers/colorcmyk.h"

colorcmyk scanColorCMYK(float c, float m, float y, float k)
{
    colorcmyk cmyk;
    cmyk.cyan = (c > 1) ? 1 : c;
    cmyk.magenta = (m > 1) ? 1 : m;
    cmyk.yellow = (y > 1) ? 1 : y;
    cmyk.key = (k > 1) ? 1 : k;
    return cmyk;
}

void printColorCMYK(colorcmyk cmyk)
{
    printf("%.3g %.3g %.3g %.3g\n", cmyk.cyan, cmyk.magenta, cmyk.yellow, cmyk.key);
}

colorcmyk plusCMYK(colorcmyk cmyk1, colorcmyk cmyk2)
{
    colorcmyk cmyk;
    cmyk.cyan = (cmyk1.cyan + cmyk2.cyan) / 2;
    cmyk.magenta = (cmyk1.magenta + cmyk2.magenta) / 2;
    cmyk.yellow = (cmyk1.yellow + cmyk2.yellow) / 2;
    cmyk.key = (cmyk1.key + cmyk2.key) / 2;
    return cmyk;
}

colorrgba CMYKtoRGBA(colorcmyk cmyk)
{
    colorrgba rgba;
    rgba.red = (255 * (1-cmyk.cyan) * (1-cmyk.key));
    rgba.green = (255 * (1-cmyk.magenta) * (1-cmyk.key));
    rgba.blue = (255 * (1-cmyk.yellow) * (1-cmyk.key));
    rgba.alpha = 255;
    return rgba;
}

colorcmyk CMYKtoCMYK(colorcmyk cmyk)
{
    return cmyk;
}

colorhsb CMYKtoHSB(colorcmyk cmyk)
{
    colorrgba rgba;
    rgba = CMYKtoRGBA(cmyk);
    return RGBAtoHSB(rgba);
}
