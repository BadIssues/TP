#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Cercle.h"

int main()
{
    //Déclarer une image OpenCV
    cv::Mat image(400, 400, CV_8UC3, cv::Scalar(255, 255, 255));

    //Créer deux instances de Cercle
    Cercle c1(200, 200, 50, 4, "test", "test"); //Les couleurs ne sont pas encore disponibles
    Cercle c2(400, 200, 50, 4, "test", "test");

    //Dessiner les deux cercles
    c1.dessiner(image);
    c2.dessiner(image);

    //Afficher dans une fenêtre OpenCV
    cv::namedWindow("Cercles", cv::WINDOW_NORMAL);//Declaring a window to show the circle
    imshow("Cercles", image);//showing the circle
    cv::waitKey(0);//Waiting for KeyStroke


    return 0;
}