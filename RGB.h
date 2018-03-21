//
//
//
// RGB.h

// Notes:   x

#ifndef RGB_H
#define RGB_H


namespace fractal {


class RGB {
public:

    double r;
    double g;
    double b;

    RGB(double r, double g, double b);


};

RGB operator-(const RGB &first, const RGB &second);


}   //namespace fractal

#endif // RGB_H
