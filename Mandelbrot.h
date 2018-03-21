//
//
//
// Mandelbrot.h

// Notes:   x

#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace fractal {

class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 1000;         //separate to drill in that its not suppose to be changed.  Also, the more iterations the better the fractal, but at a cost of runtime
public:
    Mandelbrot();
    virtual ~Mandelbrot();

    static int getIterations(double x, double y);

};

}  //namespace fractal
#endif // MANDELBROT_H
