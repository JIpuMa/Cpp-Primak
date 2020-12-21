#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>

#include "../src/colorrgba.h"
#include "../src/colorcmyk.h"
#include "../src/colorhsb.h"
#include "../src/image.h"
#include "../src/loader.h"
#include "../src/saver.h"

using namespace std;

void testRGBA();
void testCMYK();
void testHSB();
void testConvert();
void testImageLoadSave();
void testImageMask();
void runTests();

#endif // TEST_H_INCLUDED
