#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

/*����� Image �� Mask ����� ������ ���������*/
class Image
{
    unsigned _m;                 //�������� ��������� m
    unsigned _n;                 //�������� ��������� n
    vector<vector<int>> _data;   //������� ��������� m*n ����� �����
public:
    Image(unsigned m, unsigned n);                     //����������� ����� Image
    int getPixel(unsigned i, unsigned j) const;        //��������� �������� ������
    void setPixel(int clr, unsigned i, unsigned j);    //������������ �������� ������
    unsigned getM() const;                             //��������� �������� ���������
    unsigned getN() const;                             //��������� �������� ���������
    void applyFilter(const Image &mask);               //���������� ������� Mask �� Image
    void show() const;                                 //���� �������
    void save(const string& filename) const;           //���������� � ����
    static Image load(const string& filename);         //��������� ������� � �����
};

#endif // IMAGE_H_INCLUDED
