#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

class ColorRGBA;
class ColorCMYK;
class ColorHSB;

class Color
{
public:
    virtual ColorRGBA toRGBA() = 0;  //������������ ������� � �������� RGBA � RGBA
    virtual ColorCMYK toCMYK() = 0;  //������������ ������� � �������� CMYK � CMYK
    virtual ColorHSB toHSB() = 0;    //������������ ������� � �������� HSB � HSB
    virtual operator int() = 0;      //������������ ������� � ���� �����
    virtual operator float() = 0;    //������������ ������� � ����� �����
    virtual ~Color(){}               //���������� ����� Color
    virtual void printColor();       //���� �������
    virtual void printColorInt();    //���� ������� � ������ ������ �����
    virtual void printColorFloat();  //���� ������� � ������ ������� �����
};

#endif // COLOR_H_INCLUDED
