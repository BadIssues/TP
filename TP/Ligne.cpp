#include "Ligne.h"

Ligne::Ligne(int _x, int _y, int _length, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color)
    : Forme(_x, _y, _edge_width, _edge_color, _fill_color), length(_length)
{
}

int Ligne::getLength() const
{
    return length;
}

void Ligne::dessiner(cv::Mat& mat) const
{
    int x1 = getX();
    int y1 = getY();
    int x2 = getX() + getLength();
    int y2 = y1;

    line(mat, cv::Point(x1, y1), cv::Point(x2, y2), getEdge_color(), getEdge_width(), 256, 0);
}
