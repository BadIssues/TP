#include "Cercle.h"

Cercle::Cercle(int _x, int _y, int _r, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color)
{
    x = _x;
    y = _y;
    r = _r;
    edge_width = _edge_width;
    edge_color = _edge_color;
    fill_color = _fill_color;
}

int Cercle::getX() const
{
    return x;
}

int Cercle::getY() const
{
    return y;
}

int Cercle::getR() const
{
    return r;
}

int Cercle::getEdge_width() const
{
    return edge_width;
}

cv::Scalar Cercle::getEdge_color() const
{
    return edge_color;
}

cv::Scalar Cercle::getFill_color() const
{
    return fill_color;
}

void Cercle::dessiner(cv::Mat& mat) const
{
    circle(mat, cv::Point(getX(), getY()), getR(), getFill_color(), -1);
    circle(mat, cv::Point(getX(), getY()), getR(), getEdge_color(), getEdge_width());
}
