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
    double const ZOOM_SIZE = 4.0;


    FractalCreator fractalCreator(width, height);

    //Caution: this is really fragile with the numbers we are adding in and could easily break this program
    //so to fix that we would need to create a function that checks the error conditions.
    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.3, RGB(255, 0, 0));
    fractalCreator.addRange(0.5, RGB(255, 255, 0));
    fractalCreator.addRange(1.0, RGB(255, 255, 255));



    fractalCreator.addZoom(Zoom(width/2, height/2, ZOOM_SIZE / width));
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
