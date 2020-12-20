#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "image.h"

using namespace std;

/*���� ��� ��������� ������� � �����*/
class ImageLoader
{
    ifstream in;   //���� ��� ������� �������
public:
    ImageLoader(const string& filename);   //����������� ����� ImageLoader
    ~ImageLoader();                        //���������� ����� ImageLoader
    Image load();                          //���������� ������� � �����
};

#endif // LOADER_H_INCLUDED
