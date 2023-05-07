#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Cercle.h"
#include "Rectangle.h"
#include "Formes.h"

int main()
{
    //Déclarer une image OpenCV
    cv::Mat image(400, 400, CV_8UC3, cv::Scalar(255, 255, 255)); //Couleur sous format BGR et non RGB
    //Déclarer un vector permettant le stockage des formes
    std::vector<Forme*> canva;

    //Créer deux instances de Cercle
    Cercle c1(200, 200, 50, 4, cv::Scalar(0, 255, 0), cv::Scalar(255, 0, 0));
    Cercle c2(400, 200, 50, 4, cv::Scalar(255, 0, 0), cv::Scalar(0, 0, 255));
    //Créer deux instances de Rectangle
    Rectangle r1(150, 150, 100, 50, 2, cv::Scalar(0, 0, 255), cv::Scalar(255, 0, 0));
    Rectangle r2(250, 250, 50, 100, 1, cv::Scalar(255, 0, 0), cv::Scalar(255, 0, 0));

    //Ajout des formes dans le vector
    canva.push_back(&c1);
    canva.push_back(&c2);
    canva.push_back(&r1);
    canva.push_back(&r2);

    //Dessin du contenu du vector
    for (int i = 0; i < canva.size(); ++i)
    {
        canva.at(i)->dessiner(image);
    }

    //Afficher dans une fenêtre OpenCV
    cv::namedWindow("Image", cv::WINDOW_NORMAL); //Ouvrir une fenêtre pour montrer les dessins
    imshow("Image", image);//Montrer les dessins
    cv::waitKey(0); //Attendre la pression d'une touche

    return 0;
}
