#include "Cercle.h"

Cercle::Cercle(int _x, int _y, int _r, int _edge_width, std::string _edge_color, std::string _fill_color)
{
    x = _x;
    y = _y;
    r = _r;
    edge_width = _edge_width;
    edge_color = _edge_color;
    fill_color = _fill_color;
}

int Cercle::getX()
{
    return x;
}

int Cercle::getY()
{
    return y;
}

int Cercle::getR()
{
    return r;
}

int Cercle::getEdge_width()
{
    return edge_width;
}

std::string Cercle::getEdge_color()
{
    return edge_color;
}

std::string Cercle::getFill_color()
{
    return fill_color;
}

void Cercle::dessiner(cv::Mat& mat)
{
    cv::Point center(getX(), getY());//Starting Point
    int radius = getR();//Ending Point of the line
    cv::Scalar line_Color(0, 0, 0);//Color of the line
    int thickness = getEdge_width(); //thickens of the line
    circle(mat, center, radius, line_Color, thickness);//using line() function to draw the line
}
