//
//
//
// FractalCreator.h

// Notes:   A class to hold all the build fractal functions allowing main to be cleaned up

#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H


#include <string>
#include <memory>
#include <cstdint>
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Zoom.h"
#include "RGB.h"

using namespace std;


namespace fractal {

class FractalCreator {
private:
    int m_width;
    int m_height;
    int m_total{0};
    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractal;               //used to store number of iterations per pixel
    Bitmap m_bitmap;
    ZoomList m_zoomList;

    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangeTotals;

    bool m_bGotFirstRange{false};

private:
    void calculateIteration();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string name);
    int getRange(int iterations) const;

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void addRange(double rangeEnd, const RGB &rgb);
    void run(string name);
    void addZoom(const Zoom &zoom);


};

}   //namespace fractal

#endif // FRACTALCREATOR_H
