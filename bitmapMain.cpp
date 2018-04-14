//
//
//
// bitmapMain.cpp

// Notes:   This is main

#include <iostream>
#include "FractalCreator.h"
#include "Zoom.h"
#include "RGB.h"
using namespace std;
using namespace fractal;


int main(void) {


    int height = 600;
    int width  = 800;


    FractalCreator fractalCreator(width, height);

    //Caution: this is really fragile with the numbers we are adding in and could easily break this program
    //so to fix that we would need to create a function that checks the error conditions.
    //in this case the first number is the rage of iterations based in the hundreds
    //0.0 -> 0.3 means the portions of the fractal that take   0 - 300 iterations to generate the pixel
    //0.3 -> 0.5 means the portions of the fractal that take 300 - 500 iterations to generate the pixel
    //so messing around with those range values could cause some issues, the colors are fine to change to whatever you want
    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.3, RGB(255, 0, 0));
    fractalCreator.addRange(0.5, RGB(255, 255, 0));
    fractalCreator.addRange(1.0, RGB(255, 255, 255));



    //the numbers found here are what pixel you want to zoom in on.  You can find the pixel location by loading the image
    //into a photo editor and putting your cursor over a point and seeing what the pixel location is
    //its easy to find in gimp and not so easy to find in photoshop, but it is there
    //and the thrid value is the scale at which you want to zoom, adjusting this can give some strange results, but maybe you want that
    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
//    fractalCreator.addZoom(Zoom(312, m_height -304, 0.1));
//    fractalCreator.addZoom(Zoom(312, m_height -304, 0.1));
//    fractalCreator.addZoom(Zoom(554, m_height -182, 0.1));
//    fractalCreator.addZoom(Zoom(615, m_height -336, 0.1));
//    fractalCreator.addZoom(Zoom(578, m_height -320, 0.1));

    fractalCreator.run("test.bmp");

    cout << "finished" << endl;

    return 0;
}
