#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

class ColorRGBA;
class ColorCMYK;
class ColorHSB;

class Color
{
public:
    virtual ColorRGBA toRGBA() = 0;  //Петерворення кольору з сиситеми RGBA в RGBA
    virtual ColorCMYK toCMYK() = 0;  //Петерворення кольору з сиситеми CMYK в CMYK
    virtual ColorHSB toHSB() = 0;    //Петерворення кольору з сиситеми HSB в HSB
    virtual operator int() = 0;      //Перетворення кольору в ціле число
    virtual operator float() = 0;    //Перетворення кольору в дійсне число
    virtual ~Color(){}               //Деструктор класу Color
    virtual void printColor();       //Вивід кольору
    virtual void printColorInt();    //Вивід кольору у вигляді цілого числа
    virtual void printColorFloat();  //Вивід кольору у вигляді дійсного числа
};

#endif // COLOR_H_INCLUDED
