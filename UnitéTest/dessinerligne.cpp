#include "pch.h"
#include <opencv2/opencv.hpp>

void dessinerLigne(cv::Mat& image, int x1, int y1, int x2, int y2) {
    cv::line(image, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(255, 255, 255), 2);
}

int dessinerligne() {
    cv::Mat image(300, 400, CV_8UC3, cv::Scalar(0, 0, 0));  // Image noire de taille 400x300

    // Appel de la fonction dessinerLigne pour dessiner une ligne
    dessinerLigne(image, 50, 50, 200, 50);

    cv::imshow("Ligne", image);
    cv::waitKey(0);

    return 0;
}

