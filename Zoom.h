//
//
//
// Zoom.h

// Notes:   zoom feature for the fractal project


#ifndef ZOOM_H
#define ZOOM_H


namespace fractal {

struct Zoom {

    int x{0};
    int y{0};
    double scale{0.0};

    Zoom(int x, int y, double scale) : x(x), y(y), scale(scale){};

};

}   //namespace fractal


#endif // ZOOM_H
