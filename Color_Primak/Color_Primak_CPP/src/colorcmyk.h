#ifndef COLORCMYK_H_INCLUDED
#define COLORCMYK_H_INCLUDED

#include <iostream>

#include "color.h"

/*���� ��� ������ � �������� CMYK, �������� ����� Color*/
class ColorCMYK : public Color
{
    float cyan;     //�������� ������� cyan
    float magenta;  //�������� ������� magenta
    float yellow;   //�������� ������� yellow
    float key;      //�������� ������� black
public:
    ColorCMYK(float c, float m, float y, float k);  //����������� ����� ColorCMYK
    float Cyan() const;         //��������� �������� ������� cyan
    void setCyan(float c);      //������������ �������� ������� cyan
    float Magenta() const;      //��������� �������� ������� magenta
    void setMagenta(char m);    //������������ �������� ������� magenta
    float Yellow() const;       //��������� �������� ������� yellow
    void setYellow(float y);    //������������ �������� ������� yellow
    float Key() const;          //��������� �������� ������� black
    void setKey(float k);       //������������ �������� ������� black
    ColorRGBA toRGBA();         //������������ ������� � �������� CMYK � RGBA
    ColorCMYK toCMYK();         //������������ ������� � �������� CMYK � CMYK
    ColorHSB toHSB();           //������������ ������� � �������� CMYK � HSB
    operator int();             //������������ ������� � ���� �����
    operator float();           //������������ ������� � ����� �����
    void printColor();          //���� �������
    void printColorInt();       //���� ������� � ������ ������ �����
    void printColorFloat();     //���� ������� � ������ ������� �����
    friend ColorCMYK operator+(ColorCMYK& clr1, ColorCMYK& clr2);  //�������������� ��������� ��������� ��������� ������� � ������ CMYK
    friend ColorCMYK operator&(ColorCMYK& clr1, ColorCMYK& clr2);  //�������������� ��������� ��������� �������� ������� � ������ CMYK
    friend ColorCMYK operator|(ColorCMYK& clr1, ColorCMYK& clr2);  //�������������� ��������� ��������� ��'������� ������� � ������ CMYK
    friend ColorCMYK operator^(ColorCMYK& clr1, ColorCMYK& clr2);  //�������������� ��������� ��������� XOR ������� � ������ CMYK
};

#endif // COLORCMYK_H_INCLUDED
