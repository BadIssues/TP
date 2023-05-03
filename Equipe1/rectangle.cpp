#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height, int edge_width, const std::string& edge_color, const std::string& fill_color)
    : x_(x), y_(y), width_(width), height_(height), edge_width_(edge_width)
{
    if (edge_color == "blue") {
        edge_color_ = cv::Scalar(255, 0, 0);
    }
    else if (edge_color == "green") {
        edge_color_ = cv::Scalar(0, 255, 0);
    }
    else if (edge_color == "red") {
        edge_color_ = cv::Scalar(0, 0, 255);
    }
    else {
        edge_color_ = cv::Scalar(0, 0, 0);
    }

    if (fill_color == "blue") {
        fill_color_ = cv::Scalar(255, 0, 0);
    }
    else if (fill_color == "green") {
        fill_color_ = cv::Scalar(0, 255, 0);
    }
    else if (fill_color == "red") {
        fill_color_ = cv::Scalar(0, 0, 255);
    }
    else {
        fill_color_ = cv::Scalar(0, 0, 0);
    }
}

void Rectangle::dessiner(cv::Mat& image) const
{
    int x1 = x_ - width_ / 2;
    int y1 = y_ - height_ / 2;
    int x2 = x_ + width_ / 2;
    int y2 = y_ + height_ / 2;

    cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), fill_color_, -1);
    cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), edge_color_, edge_width_);
}
