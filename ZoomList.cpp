//
//
//
// ZoomList.cpp

// Notes:   x


#include "ZoomList.h"



namespace fractal {

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height) {

}

void ZoomList::add(const Zoom &zoom) {
    zooms.push_back(zoom);

    m_xCenter += (zoom.x - m_width / 2) * m_scale;
    m_yCenter += -(zoom.y - m_height/ 2) * m_scale;     //the negative sign is due to the way y starts from the top, giving a more natural input / feel to the zoom

    m_scale *= zoom.scale;
}

pair<double, double> ZoomList::doZoom(int x, int y) {

    double xFractal = (x - m_width/2) * m_scale + m_xCenter;
    double yFractal = (y - m_height/2) * m_scale + m_yCenter;

    return pair<double, double>(xFractal, yFractal);
}



}   //namespace fractal
