#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void DessinerLigne(cv::Mat& image, int x1, int y1, int x2, int y2, const cv::Scalar& couleur, int epaisseur);
