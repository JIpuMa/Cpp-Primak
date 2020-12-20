#include "test.h"

void runTests()
{
    cout << "\nTest RGBA:\n" << endl;
    testRGBA();

    cout << "\nTest CMYK:\n" << endl;
    testCMYK();

    cout << "\nTest HSB:\n" << endl;
    testHSB();

    cout << "\nTest convert:\n" << endl;
    testConvert();

    cout << "\nTest image load and save:\n" << endl;
    testImageLoadSave();

    cout << "\nTest apply filter:\n" << endl;
    testImageMask();

    cout << "\nPushka\n" << endl;
}

void testRGBA()
{
    ColorRGBA c1(14,54,241,0);
    ColorRGBA c2(88,123,300);
    ColorRGBA c3 = c1 + c2;

    c1.printColor();
    c1.printColorInt();
    c1.printColorFloat();

    c2.printColor();
    c2.printColorInt();
    c2.printColorFloat();

    c3.printColor();

    c3 = c1 & c2;
    c3.printColor();

    c3 = c1 | c2;
    c3.printColor();

    c3 = c1 ^ c2;
    c3.printColor();
}

void testCMYK()
{
    ColorCMYK c1(0.5f,0.3f,1.0f,0.4f);
    ColorCMYK c2(0.0f,1.6f,0.4f,0.2f);
    ColorCMYK c3 = c1 + c2;

    c1.printColor();
    c1.printColorInt();
    c1.printColorFloat();

    c2.printColor();
    c2.printColorInt();
    c2.printColorFloat();

    c3.printColor();

    c3 = c1 & c2;
    c3.printColor();

    c3 = c1 | c2;
    c3.printColor();

    c3 = c1 ^ c2;
    c3.printColor();
}

void testHSB()
{
    ColorHSB c1(167,0.3f,1.0f);
    ColorHSB c2(400,1.6f,0.4f);
    ColorHSB c3 = c1 + c2;

    c1.printColor();
    c1.printColorInt();
    c1.printColorFloat();

    c2.printColor();
    c2.printColorInt();
    c2.printColorFloat();

    c3.printColor();

    c3 = c1 & c2;
    c3.printColor();

    c3 = c1 | c2;
    c3.printColor();

    c3 = c1 ^ c2;
    c3.printColor();
}

void testConvert()
{
    ColorRGBA rgb1(45,145,45);
    ColorCMYK cmyk1 = rgb1.toCMYK();;
    ColorHSB hsb1 = rgb1.toHSB();
    ColorRGBA rgb2 = cmyk1.toRGBA();
    ColorRGBA rgb3 = hsb1.toRGBA();
    ColorCMYK cmyk2 = hsb1.toCMYK();
    ColorHSB hsb2 = cmyk1.toHSB();

    rgb1.printColor();
    cmyk1.printColor();
    hsb1.printColor();
    rgb2.printColor();
    rgb3.printColor();
    cmyk2.printColor();
    hsb2.printColor();
}

void testImageLoadSave()
{
    Image img1(4,5);
    cout << "Before save:" << endl;
    img1.setPixel(12,1,2);
    img1.show();
    img1.save("..//Color_Primak_CPP//tests//image.txt");
    cout << "After load:" << endl;
    Image img2 = Image::load("..//Color_Primak_CPP//tests//image.txt");
    img2.show();
}

void testImageMask()
{
    Image img = Image::load("..//Color_Primak_CPP//tests//image2.txt");
    cout << "Image:" << endl;
    img.show();
    Image mask = Image::load("..//Color_Primak_CPP//tests//mask2.txt");
    cout << "Mask:" << endl;
    mask.show();
    img.applyFilter(mask);
    cout << "Filtered image:" << endl;
    img.show();
}
