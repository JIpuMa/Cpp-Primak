#ifndef COLORHSB_H_INCLUDED
#define COLORHSB_H_INCLUDED

#include <iostream>

#include "color.h"

/*���� ��� ������ � �������� HSB, �������� ����� Color*/
class ColorHSB: public Color
{
    unsigned short hue;  //�������� ��������� hue
    float saturation;    //�������� ��������� saturation
    float brightness;    //�������� ��������� brightness
public:
    ColorHSB(unsigned short h, float s, float b);   //����������� ����� ColorHSB
    unsigned short Hue() const;      //��������� �������� ��������� hue
    void setHue(unsigned short h);   //������������ �������� ��������� hue
    float Saturation() const;        //��������� �������� ��������� saturation
    void setSaturation(float s);     //������������ �������� ��������� saturation
    float Brightness() const;        //��������� �������� ��������� brightness
    void setBrightness(float b);     //������������ �������� ��������� brightness
    ColorRGBA toRGBA();              //������������ ������� � �������� HSB � RGBA
    ColorCMYK toCMYK();              //������������ ������� � �������� HSB � CMYK
    ColorHSB toHSB();                //������������ ������� � �������� HSB � HSB
    operator int();                  //������������ ������� � ���� �����
    operator float();                //������������ ������� � ����� �����
    void printColor();               //���� �������
    void printColorInt();            //���� ������� � ������ ������ �����
    void printColorFloat();          //���� ������� � ������ ������� �����
    friend ColorHSB operator+(ColorHSB& clr1, ColorHSB& clr2);   //�������������� ��������� ��������� ��������� ������� � ������ HSB
    friend ColorHSB operator&(ColorHSB& clr1, ColorHSB& clr2);   //�������������� ��������� ��������� �������� ������� � ������ HSB
    friend ColorHSB operator|(ColorHSB& clr1, ColorHSB& clr2);   //�������������� ��������� ��������� ��'������� ������� � ������ HSB
    friend ColorHSB operator^(ColorHSB& clr1, ColorHSB& clr2);   //�������������� ��������� ��������� XOR ������� � ������ HSB
};

#endif // COLORHSB_H_INCLUDED
