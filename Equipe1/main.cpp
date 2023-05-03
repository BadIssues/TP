#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "Rectangle.h"

int main() {
    // Créer une image OpenCV
    cv::Mat image(400, 400, CV_8UC3, cv::Scalar(255, 255, 255));

    // Créer deux instances de Rectangle
    Rectangle rect1(150, 150, 100, 50, 2, "blue", "green");
    Rectangle rect2(250, 250, 50, 100, 1, "red", "blue");

    // Dessiner les deux rectangles sur l'image
    rect1.dessiner(image);
    rect2.dessiner(image);

    // Afficher l'image dans une fenêtre OpenCV
    cv::namedWindow("Rectangles", cv::WINDOW_NORMAL);
    cv::imshow("Rectangles", image);
    cv::waitKey(0);

    return 0;
}







