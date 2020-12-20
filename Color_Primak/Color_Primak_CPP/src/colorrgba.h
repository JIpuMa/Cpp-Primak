#ifndef COLORRGBA_H_INCLUDED
#define COLORRGBA_H_INCLUDED

#include <iostream>

#include "color.h"

/*���� ��� ������ � �������� HSB, �������� ����� Color*/
class ColorRGBA : public Color
{
    typedef unsigned short TUS;  //��������� �������� ���� � ����
    TUS red;    //�������� ������� red
    TUS green;  //�������� ������� green
    TUS blue;   //�������� ������� blue
    TUS alpha;  //�������� ��������� alpha
public:
    ColorRGBA(TUS r, TUS g, TUS b, TUS a = 255);  //����������� ����� ColorRGBA
    ColorRGBA(int val = 0);  //����������� ������� � ������ �����
    TUS Red() const;         //��������� �������� ������� red
    void setRed(TUS r);      //������������ �������� ������� red
    TUS Green() const;       //��������� �������� ������� green
    void setGreen(TUS g);    //������������ �������� ������� green
    TUS Blue() const;        //��������� �������� ������� blue
    void setBlue(TUS b);     //������������ �������� ������� blue
    TUS Alpha() const;       //��������� �������� ��������� alpha
    void setAlpha(TUS a);    //������������ �������� ��������� alpha
    ColorRGBA toRGBA();      //������������ ������� � �������� HSB � RGBA
    ColorCMYK toCMYK();      //������������ ������� � �������� HSB � CMYK
    ColorHSB toHSB();        //������������ ������� � �������� HSB � HSB
    operator int();          //������������ ������� � ���� �����
    operator float();        //������������ ������� � ����� �����
    void printColor();       //���� �������
    void printColorInt();    //���� ������� � ������ ������ �����
    void printColorFloat();  //���� ������� � ������ ������� �����
    friend ColorRGBA operator+(ColorRGBA& clr1, ColorRGBA& clr2);   //�������������� ��������� ��������� ��������� ������� � ������ RGBA
    friend ColorRGBA operator&(ColorRGBA& clr1, ColorRGBA& clr2);   //�������������� ��������� ��������� �������� ������� � ������ RGBA
    friend ColorRGBA operator|(ColorRGBA& clr1, ColorRGBA& clr2);   //�������������� ��������� ��������� ��'������� ������� � ������ RGBA
    friend ColorRGBA operator^(ColorRGBA& clr1, ColorRGBA& clr2);   //�������������� ��������� ��������� XOR ������� � ������ RGBA
};

#endif // COLORRGBA_H_INCLUDED
