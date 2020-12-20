#ifndef COLORCMYK_H_INCLUDED
#define COLORCMYK_H_INCLUDED

#include <iostream>

#include "color.h"

/*Клас для роботи з системою CMYK, наслідник класу Color*/
class ColorCMYK : public Color
{
    float cyan;     //Значення кольору cyan
    float magenta;  //Значення кольору magenta
    float yellow;   //Значення кольору yellow
    float key;      //Значення кольору black
public:
    ColorCMYK(float c, float m, float y, float k);  //Конструктор класу ColorCMYK
    float Cyan() const;         //Отримання значення кольору cyan
    void setCyan(float c);      //Встановлення значення кольору cyan
    float Magenta() const;      //Отримання значення кольору magenta
    void setMagenta(char m);    //Встановлення значення кольору magenta
    float Yellow() const;       //Отримання значення кольору yellow
    void setYellow(float y);    //Встановлення значення кольору yellow
    float Key() const;          //Отримання значення кольору black
    void setKey(float k);       //Встановлення значення кольору black
    ColorRGBA toRGBA();         //Петерворення кольору з сиситеми CMYK в RGBA
    ColorCMYK toCMYK();         //Петерворення кольору з сиситеми CMYK в CMYK
    ColorHSB toHSB();           //Петерворення кольору з сиситеми CMYK в HSB
    operator int();             //Перетворення кольору в ціле число
    operator float();           //Перетворення кольору в дійсне число
    void printColor();          //Вивід кольору
    void printColorInt();       //Вивід кольору у вигляді цілого числа
    void printColorFloat();     //Вивід кольору у вигляді дійсного числа
    friend ColorCMYK operator+(ColorCMYK& clr1, ColorCMYK& clr2);  //Перевизначення оператора побітового додавання кольорів в системі CMYK
    friend ColorCMYK operator&(ColorCMYK& clr1, ColorCMYK& clr2);  //Перевизначення оператора побітового перетину кольорів в системі CMYK
    friend ColorCMYK operator|(ColorCMYK& clr1, ColorCMYK& clr2);  //Перевизначення оператора побітового об'єднання кольорів в системі CMYK
    friend ColorCMYK operator^(ColorCMYK& clr1, ColorCMYK& clr2);  //Перевизначення оператора побітового XOR кольорів в системі CMYK
};

#endif // COLORCMYK_H_INCLUDED
