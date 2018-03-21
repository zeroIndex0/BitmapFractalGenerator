//
//
//
// BitmapFileHeader.h

// Notes:   x

#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include<cstdint>
using namespace std;

#pragma pack(push, 2)           //force C++ to align everything on two byte bounds and get rid of padding, padding would make this not work.

namespace fractal {

struct BitmapFileHeader {
    //two bytes at the top of the file have to be B and M in order for a photo viewer to understand this is a bitmap
    char header[2]{'B', 'M'};
    int32_t fileSize;           //this must be 32 bits so an integer is not safe to use since it could be 64 bits on some machines
    int32_t reserved{0};
    int32_t dataOffset;
};

}
#pragma pack(pop)               //stops the stopped padding


#endif // BITMAPFILEHEADER_H
