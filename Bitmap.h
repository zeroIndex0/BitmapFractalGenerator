//
//
//
// Bitmap.h

// Notes:   Bitmap class header file

#ifndef BITMAP_H
#define BITMAP_H

#include<string>
#include<cstdint>
#include<memory>
using namespace std;

namespace fractal {

class Bitmap {
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr}; //using smart pointers, pointless comment, sure, but for me its a good reminder, so there!

public:
    Bitmap(int width, int height);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);  //uint8_t is an 8 bit int or the size of an unsigned char
    bool write(string filename);            //create a bitmap. Set to bool return value because sometimes you cant write files. You may not have permission
    virtual ~Bitmap();
};

} // namespace fractal
#endif // BITMAP_H
