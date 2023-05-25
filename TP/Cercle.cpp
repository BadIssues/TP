#include "Cercle.h"

Cercle::Cercle(int _x, int _y, int _r, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color)
    : Forme(_x, _y, _edge_width, _edge_color, _fill_color), r(_r)
{
}

int Cercle::getR() const
{
    return r;
}

void Cercle::dessiner(cv::Mat& mat) const
{
    circle(mat, cv::Point(getX(), getY()), getR(), getFill_color(), -1, 256, 0);
    circle(mat, cv::Point(getX(), getY()), getR(), getEdge_color(), getEdge_width(), 256, 0);
}
