#ifndef COLORRGBA_H_INCLUDED
#define COLORRGBA_H_INCLUDED

#include <iostream>

#include "color.h"

/*Клас для роботи з системою HSB, наслідник класу Color*/
class ColorRGBA : public Color
{
    typedef unsigned short TUS;  //Створення власного типу в класі
    TUS red;    //Значення кольору red
    TUS green;  //Значення кольору green
    TUS blue;   //Значення кольору blue
    TUS alpha;  //Значення параметру alpha
public:
    ColorRGBA(TUS r, TUS g, TUS b, TUS a = 255);  //Конструктор класу ColorRGBA
    ColorRGBA(int val = 0);  //Переведення кольору з цілого числа
    TUS Red() const;         //Отримання значення кольору red
    void setRed(TUS r);      //Встановлення значення кольору red
    TUS Green() const;       //Отримання значення кольору green
    void setGreen(TUS g);    //Встановлення значення кольору green
    TUS Blue() const;        //Отримання значення кольору blue
    void setBlue(TUS b);     //Встановлення значення кольору blue
    TUS Alpha() const;       //Отримання значення параметру alpha
    void setAlpha(TUS a);    //Встановлення значення параметру alpha
    ColorRGBA toRGBA();      //Петерворення кольору з сиситеми HSB в RGBA
    ColorCMYK toCMYK();      //Петерворення кольору з сиситеми HSB в CMYK
    ColorHSB toHSB();        //Петерворення кольору з сиситеми HSB в HSB
    operator int();          //Перетворення кольору в ціле число
    operator float();        //Перетворення кольору в дійсне число
    void printColor();       //Вивід кольору
    void printColorInt();    //Вивід кольору у вигляді цілого числа
    void printColorFloat();  //Вивід кольору у вигляді дійсного числа
    friend ColorRGBA operator+(ColorRGBA& clr1, ColorRGBA& clr2);   //Перевизначення оператора побітового додавання кольорів в системі RGBA
    friend ColorRGBA operator&(ColorRGBA& clr1, ColorRGBA& clr2);   //Перевизначення оператора побітового перетину кольорів в системі RGBA
    friend ColorRGBA operator|(ColorRGBA& clr1, ColorRGBA& clr2);   //Перевизначення оператора побітового об'єднання кольорів в системі RGBA
    friend ColorRGBA operator^(ColorRGBA& clr1, ColorRGBA& clr2);   //Перевизначення оператора побітового XOR кольорів в системі RGBA
};

#endif // COLORRGBA_H_INCLUDED
