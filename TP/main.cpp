#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ligne.h"

int main()
{
    //Déclarer une image OpenCV
    cv::Mat image(cv::Size(400, 400), CV_8UC3, cv::Scalar(255, 255, 255)); //Couleur sous format BGR et non RGB
    //Déclarer un vector permettant le stockage des formes
    std::vector<Forme*> canva;

    //Créer deux instances de Cercle
    Cercle c1(200, 200, 50, 4, cv::Scalar(0, 255, 0), cv::Scalar(255, 0, 0));
    Cercle c2(400, 200, 50, 4, cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    //Créer deux instances de Rectangle
    Rectangle r1(150, 150, 100, 50, 2, cv::Scalar(0, 0, 255), cv::Scalar(255, 0, 0));
    Rectangle r2(250, 250, 50, 100, 4, cv::Scalar(255, 0, 0), cv::Scalar(255, 255, 0));
    //Créer une instance de Ligne
    Ligne l1(100, 100, 50, 2, cv::Scalar(0, 0, 255), cv::Scalar(0, 0, 0));
    //Créer une instance de Triangle
    Triangle t1(100, 300, 40, 2, cv::Scalar(255, 100, 200), cv::Scalar(0, 0, 0));

    //Ajout des formes dans le vector
    canva.push_back(&c1);
    canva.push_back(&c2);
    canva.push_back(&r1);
    canva.push_back(&r2);
    canva.push_back(&l1);
    canva.push_back(&t1);

    //Dessin du contenu du vector
    for (int i = 0; i < canva.size(); ++i)
    {
        canva.at(i)->dessiner(image);
    }

    while (true)
    {
        double angle = 90;//Permet de définir l'angle de rotation
        cv::Point2f center(image.cols / 2.0, image.rows / 2.0);
        cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);
        cv::warpAffine(image, image, rotationMatrix, image.size());//Permet de déssiner la rotation

        //Afficher dans une fenêtre OpenCV
        cv::namedWindow("Image", cv::WINDOW_NORMAL); //Ouvrir une fenêtre pour montrer les dessins
        imshow("Image", image);//Montrer les dessins
        cv::waitKey(100); //Delay entre chaque rotation
    }

    return 0;
}