#include "../headers/colorhsb.h"

colorhsb scanColorHSB(unsigned h, float s, float b)
{
    colorhsb hsb;
    hsb.hue = (h > 360) ? 360 : h;
    hsb.saturation = (s > 1) ? 1 : s;
    hsb.brightness = (b > 1) ? 1 : b;
    return hsb;
}

void printColorHSB(colorhsb hsb)
{
    printf("%d %.3g %.3g\n", hsb.hue, hsb.saturation, hsb.brightness);
}

colorhsb plusHSB(colorhsb hsb1, colorhsb hsb2)
{
    colorhsb hsb;
    hsb.hue = (hsb1.hue + hsb2.hue) / 2;
    hsb.saturation = (hsb1.saturation + hsb2.saturation) / 2;
    hsb.brightness = (hsb1.brightness + hsb2.brightness) / 2;
    return hsb;
}

colorhsb HSBtoHSB(colorhsb hsb)
{
    return hsb;
}

colorrgba HSBtoRGBA(colorhsb hsb)
{
    float c = hsb.brightness * hsb.saturation;
    float h = hsb.hue/60.0f;
    h = fmodf(h,2) - 1.0f;
    float x = c * (1.0f - fabsf(h));
    float m = hsb.brightness - c;
    float r = 0, g = 0, b = 0;
    if(hsb.hue < 60)
    {
        r = c;
        g = x;
    }
    else if (hsb.hue >= 60 && hsb.hue < 120)
    {
        r = x;
        g = c;
    }
    else if (hsb.hue >= 120 && hsb.hue < 180)
    {
        g = c;
        b = x;
    }
    else if (hsb.hue >= 180 && hsb.hue < 240)
    {
        g = x;
        b = c;
    }
    else if (hsb.hue >= 240 && hsb.hue < 300)
    {
        r = x;
        b = c;
    }
    else
    {
        r = c;
        b = x;
    }
    colorrgba rgba;
    rgba.red = ((r+m)*255.0f);
    rgba.green = ((g+m)*255.0f);
    rgba.blue = ((b+m)*255.0f);
    rgba.alpha = 255;
    return rgba;
}

colorcmyk HSBtoCMYK(colorhsb hsb)
{
    colorrgba rgba;
    rgba = HSBtoRGBA(hsb);
    return RGBAtoCMYK(rgba);
}
