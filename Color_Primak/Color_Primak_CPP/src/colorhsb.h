#ifndef COLORHSB_H_INCLUDED
#define COLORHSB_H_INCLUDED

#include <iostream>

#include "color.h"

/*Клас для роботи з системою HSB, наслідник класу Color*/
class ColorHSB: public Color
{
    unsigned short hue;  //Значення параметру hue
    float saturation;    //Значення параметру saturation
    float brightness;    //Значення параметру brightness
public:
    ColorHSB(unsigned short h, float s, float b);   //Конструктор класу ColorHSB
    unsigned short Hue() const;      //Отримання значення параметру hue
    void setHue(unsigned short h);   //Встановлення значення параметру hue
    float Saturation() const;        //Отримання значення параметру saturation
    void setSaturation(float s);     //Встановлення значення параметру saturation
    float Brightness() const;        //Отримання значення параметру brightness
    void setBrightness(float b);     //Встановлення значення параметру brightness
    ColorRGBA toRGBA();              //Петерворення кольору з сиситеми HSB в RGBA
    ColorCMYK toCMYK();              //Петерворення кольору з сиситеми HSB в CMYK
    ColorHSB toHSB();                //Петерворення кольору з сиситеми HSB в HSB
    operator int();                  //Перетворення кольору в ціле число
    operator float();                //Перетворення кольору в дійсне число
    void printColor();               //Вивід кольору
    void printColorInt();            //Вивід кольору у вигляді цілого числа
    void printColorFloat();          //Вивід кольору у вигляді дійсного числа
    friend ColorHSB operator+(ColorHSB& clr1, ColorHSB& clr2);   //Перевизначення оператора побітового додавання кольорів в системі HSB
    friend ColorHSB operator&(ColorHSB& clr1, ColorHSB& clr2);   //Перевизначення оператора побітового перетину кольорів в системі HSB
    friend ColorHSB operator|(ColorHSB& clr1, ColorHSB& clr2);   //Перевизначення оператора побітового об'єднання кольорів в системі HSB
    friend ColorHSB operator^(ColorHSB& clr1, ColorHSB& clr2);   //Перевизначення оператора побітового XOR кольорів в системі HSB
};

#endif // COLORHSB_H_INCLUDED
