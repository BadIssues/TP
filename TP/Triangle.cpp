#include "Triangle.h"

Triangle::Triangle(int _x, int _y, int _width, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color)
    : Forme(_x, _y, _edge_width, _edge_color, _fill_color), width(_width)
{
}

int Triangle::getWidth() const
{
    return width;
}

void Triangle::dessiner(cv::Mat& image) const
{
    int x1 = getX() - (getWidth() / 2);
    int y1 = getY() - (getWidth() * 0.866 / 2);
    int x2 = x1 + getWidth();
    int y2 = y1;
    int x3 = getX();
    int y3 = getY() + (getWidth() * 0.866 / 2);
    
    cv::line(image, cv::Point(x1, y1), cv::Point(x2, y2), getEdge_width(), 8, 0);
    cv::line(image, cv::Point(x2, y2), cv::Point(x3, y3), getEdge_width(), 8, 0);
    cv::line(image, cv::Point(x3, y3), cv::Point(x1, y1), getEdge_width(), 8, 0);


}
