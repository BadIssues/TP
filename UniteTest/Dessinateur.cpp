#include "pch.h"
#include "Dessinateur.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

void DessinerLigne(cv::Mat& image, int x1, int y1, int x2, int y2, const cv::Scalar& couleur, int epaisseur)
{
    cv::line(image, cv::Point(x1, y1), cv::Point(x2, y2), couleur, epaisseur);
}
