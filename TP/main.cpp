#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Cercle.h"
#include "Rectangle.h"
#include "Formes.h"

int main()
{
    //Déclarer une image OpenCV
    cv::Mat image(400, 400, CV_8UC3, cv::Scalar(255, 255, 255)); //Couleur sous format BGR et non RGB

    //Créer deux instances de Cercle
    Formes c1(200, 200, 50, 4, cv::Scalar(0, 255, 0), cv::Scalar(255, 0, 0));
    Formes c2(400, 200, 50, 4, cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));

    //Dessiner les deux cercles
    c1.dessiner(image);
    c2.dessiner(image);

    // Créer deux instances de Rectangle
    Formes rect1(150, 150, 100, 50, 2, cv::Scalar(0, 0, 255), cv::Scalar(255, 0, 0));
    Formes rect2(250, 250, 50, 100, 1, cv::Scalar(255, 0, 0), cv::Scalar(255, 0, 0));

    // Dessiner les deux rectangles sur l'image
    rect1.dessiner(image);
    rect2.dessiner(image);

    //Afficher dans une fenêtre OpenCV
    cv::namedWindow("Formes", cv::WINDOW_NORMAL); //Ouvrir une fenêtre pour montrer les dessins
    imshow("Formes", image);//Montrer les dessins
    cv::waitKey(0); //Attendre la pression d'une touche


    return 0;
}
