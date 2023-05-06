#include "Rectangle.h"

Rectangle::Rectangle(int x_, int y_, int width_, int height_, int edge_width_, cv::Scalar edge_color_, cv::Scalar fill_color_)
{

    x = x_;
    y = y_;
    width = width_;
    height = height_;
    edge_width = edge_width_;
    edge_color = edge_color_;
    fill_color = fill_color_;
}

int Rectangle::getX() const
{
    return x;
}

int Rectangle::getY() const
{
    return y;
}

int Rectangle::getWidth() const
{
    return width;
}
int Rectangle::getHeight() const
{
    return height;
}

int Rectangle::getEdge_width() const
{
    return edge_width;
}

cv::Scalar Rectangle::getEdge_color() const
{
    return edge_color;
}

cv::Scalar Rectangle::getFill_color() const
{
    return fill_color;
}

void Rectangle::dessiner(cv::Mat& image) const
{
    int x1 = getX() - getWidth() / 2;
    int y1 = getY() - getHeight() / 2;
    int x2 = getX() + getWidth() / 2;
    int y2 = getY() + getHeight() / 2;

    cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), getFill_color(), -1);
    cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), getEdge_color(), getEdge_width());
}
