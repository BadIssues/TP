#pragma one
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height, int edge_width, const std::string& edge_color, const std::string& fill_color);
    void dessiner(cv::Mat& image) const;

private:
    int x_, y_, width_, height_;
    int edge_width_;
    cv::Scalar edge_color_;
    cv::Scalar fill_color_;
};