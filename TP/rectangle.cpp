#include "Rectangle.h"

Rectangle::Rectangle(int _x, int _y, int _width, int _height, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color)
    : Forme(_x, _y, _edge_width, _edge_color, _fill_color), width(_width), height(_height)
{
}

int Rectangle::getWidth() const
{
    return width;
}
int Rectangle::getHeight() const
{
    return height;
}

void Rectangle::dessiner(cv::Mat& image) const
{
    //Coin supérieur gauche
    int x1 = getX() - getWidth() / 2;
    int y1 = getY() - getHeight() / 2;
    //Coin supérieur droit
    int x2 = getX() + getWidth() / 2;
    int y2 = getY() + getHeight() / 2;

    cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), getFill_color(), -1, 256, 0);
    cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), getEdge_color(), getEdge_width(), 256, 0);
}
