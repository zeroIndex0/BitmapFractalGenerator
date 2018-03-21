//
//
//
// Bitmap.cpp

// Notes:   A bitmap class

#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace fractal;
using namespace std;

namespace fractal {

//setting m_pPixels here is telling the compiler how much memory to set aside for the array.  We also dont need a destructor since its a smart pointer 'unique_ptr'
Bitmap::Bitmap(int width, int height) :
    m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}) {  //the amount of memory to point at width*height*3 every pixel has 3 bytes

}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t *pPixel = m_pPixels.get();          //must use .get() to access smart pointers values.

    pPixel += (y * 3) * m_width + (x * 3);      //multiplying by three since each pixel has 3 bytes... the passed in red, green, and blue
    //these are built in reverse order due to bitmaps being a little Indian style, could be something to easily trip you up later!
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

bool Bitmap::write(string filename) {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize   = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.width      = m_width;
    infoHeader.height     = m_height;


    ofstream file;
    file.open(filename, ios::out|ios::binary);
    if(!file) {
        return false;
    }
    file.write((char *)&fileHeader, sizeof(fileHeader));            //the first argument has to be a char * so it needs to be cast
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)m_pPixels.get(), m_width * m_height * 3);    //unique_ptr.get() allows you to get the real deal pointer from a shared pointer allowing it to be cast
    file.close();
    if(!file) {
        return false;
    }

    return true;
}

Bitmap::~Bitmap() {}

} //namespace fractal
