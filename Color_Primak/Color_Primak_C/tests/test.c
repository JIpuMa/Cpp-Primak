#include "test.h"

void runTest()
{
    printf("\nTest RGBA:\n");
    testRGBA();

    printf("\nTest CMYK:\n");
    testCMYK();

    printf("\nTest HSB:\n");
    testHSB();

    printf("\nTest convert:\n");
    testConvert();
}

void testRGBA()
{
    colorrgba rgba1;
    rgba1 = scanColorRGBA(201, 10, 40, 23);
    printColorRGBA(rgba1);
    colorrgba rgba2;
    rgba2 = scanColorRGBA(111, 215, 405, 199);
    printColorRGBA(rgba2);
    colorrgba rgba3;
    rgba3 = plusRGBA(rgba1, rgba2);
    printColorRGBA(rgba3);
}

void testCMYK()
{
    colorcmyk cmyk1;
    cmyk1 = scanColorCMYK(0.1, 0.5, 1.1, 0.5);
    printColorCMYK(cmyk1);
    colorcmyk cmyk2;
    cmyk2 = scanColorCMYK(2, 0.7, 0.1, 0.9);
    printColorCMYK(cmyk2);
    colorcmyk cmyk3;
    cmyk3 = plusCMYK(cmyk1, cmyk2);
    printColorCMYK(cmyk3);
}

void testHSB()
{
    colorhsb hsb1;
    hsb1 = scanColorHSB(288, 0.2, 0.1);
    printColorHSB(hsb1);
    colorhsb hsb2;
    hsb2 = scanColorHSB(45, 0.8, 0.1);
    printColorHSB(hsb2);
    colorhsb hsb3;
    hsb3 = plusHSB(hsb1, hsb2);
    printColorHSB(hsb3);
}

void testConvert()
{
    colorrgba rgba1;
    rgba1 = scanColorRGBA(167, 201, 17, 300);
    printColorRGBA(rgba1);
    colorcmyk cmyk1;
    cmyk1 = RGBAtoCMYK(rgba1);
    printColorCMYK(cmyk1);
    colorhsb hsb1;
    hsb1 = RGBAtoHSB(rgba1);
    printColorHSB(hsb1);

    colorcmyk cmyk2;
    cmyk2 = scanColorCMYK(2, 0.7, 0.1, 0.9);
    printColorCMYK(cmyk2);
    colorrgba rgba2;
    rgba2 = CMYKtoRGBA(cmyk2);
    printColorRGBA(rgba2);
    colorhsb hsb2;
    hsb2 = CMYKtoHSB(cmyk2);
    printColorHSB(hsb2);

    colorhsb hsb3;
    hsb3 = scanColorHSB(45, 0.8, 0.1);
    printColorHSB(hsb3);
    colorrgba rgba3;
    rgba3 = HSBtoRGBA(hsb3);
    printColorRGBA(rgba3);
    colorcmyk cmyk3;
    cmyk3 = HSBtoCMYK(hsb3);
    printColorCMYK(cmyk3);
}
