//
//
//
// FractalCreator.cpp

// Notes:   x


#include "FractalCreator.h"
#include <assert.h>


namespace fractal {

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
    m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if(m_bGotFirstRange) {
        m_rangeTotals.push_back(0);
    }
    m_bGotFirstRange = true;

}

int FractalCreator::getRange(int iterations) const {
    int range = 0;

    for(int i = 1; i < m_ranges.size(); i++) {      //the complier warns about comparing unsigned and signed int here because a vector is always unsigned, but its alright
        range = i;

        if(m_ranges[i] > iterations) {
            break;
        }
    }

    range--;        //this forces a zero index.  Since the for loop starts at 1;

    assert(range > -1);
    assert(range < m_ranges.size());               //again, complaining about unsigned and singed comparison, but range is asserted to never be negative, so its fine

    return range;
}


void FractalCreator::addZoom(const Zoom &zoom) {
    m_zoomList.add(zoom);
}


void FractalCreator::run(string name) {

    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap("test.bmp");
}



//had a bug here for a while driving me insane, but it was just one misplaced ')'  figures.
FractalCreator::FractalCreator(int width, int height) :
    m_width(width),
    m_height(height),
    m_histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{}),
    m_fractal(new int[m_width * m_height]{}),
    m_bitmap(m_width, m_height),
    m_zoomList(m_width, m_height){
        m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width)); //The 4.0 is the zoom size
}

FractalCreator::~FractalCreator(){}


void FractalCreator::calculateIteration() {
    for(int y = 0; y < m_height; y++) {
        for(int x = 0; x < m_width; x++) {

            pair<double, double> coords = m_zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            m_fractal[y * m_width + x] = iterations;

            if(iterations != Mandelbrot::MAX_ITERATIONS) {                  //gets rid of the very last iteration setting as that has the most pixels and they are all garbage anyway
                m_histogram[iterations]++;
            }//commenting out this if statement will get rid of the black portions and allow the color to be in the addRange function set (1 of 2 if statements to comment out)
        }
    }

}


void FractalCreator::calculateRangeTotals() {

    int rangeIndex = 0;

    for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = m_histogram[i];

        //this should ignore the first range as we are starting from the first and dont want to add the start, in the function addRange(double, RBG) called in main
        if(i >= m_ranges[rangeIndex+1]) {
            rangeIndex++;
        }

        m_rangeTotals[rangeIndex] += pixels;
    }
}


void FractalCreator::calculateTotalIterations() {

    for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        m_total += m_histogram[i];
    }
}


void FractalCreator::drawFractal() {

    for(int y = 0; y < m_height; y++) {
        for(int x = 0; x < m_width; x++) {


            int iterations = m_fractal[y * m_width + x];

            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];

            RGB &startColor = m_colors[range];
            RGB &endColor = m_colors[range + 1];
            RGB colorDiff = endColor - startColor;

            uint8_t red   = 0;
            uint8_t green = 0;
            uint8_t blue  = 0;


            if(iterations != Mandelbrot::MAX_ITERATIONS) {      //dont use the last iteration value

                int totalPixels = 0;

                for(int i = rangeStart; i <= iterations; i++) {
                    totalPixels += m_histogram[i];
                }

                red = startColor.r + colorDiff.r *   (double)totalPixels / rangeTotal;
                green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
                blue = startColor.b + colorDiff.b *  (double)totalPixels / rangeTotal;
            }//commenting out this if statement will get rid of the black portions and allow the color to be in the addRange function set (2 of 2 if statements to comment out)

            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }

}


void FractalCreator::writeBitmap(string name) {
    m_bitmap.write(name);
}


}   //namespace fractal
