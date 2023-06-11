#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "readFile.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ligne.h"

int main()
{
    //Déclarer une image OpenCV
    cv::Mat image(cv::Size(400, 400), CV_8UC3, cv::Scalar(255, 255, 255)); //Couleur sous format BGR et non RGB
    
    /*//Déclarer un vector permettant le stockage des formes
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
    }*/



    //Déclarer des vector permettant le stockage des formes
    std::vector<Cercle> circleLayers;
    std::vector<Rectangle> rectangleLayers;
    std::vector<Ligne> lineLayers;
    std::vector<Triangle> triangleLayers;
    //Déclarer un vector rassemblant l'adresse de toutes les formes
    std::vector<Forme*> layers;

    //Lire le fichier texte
    std::vector<std::vector<std::string>> cmd = readFile();

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == "cercle")
        {
            Cercle c(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), cv::Scalar(std::stoi(cmd[i][6]), std::stoi(cmd[i][7]), std::stoi(cmd[i][8])), cv::Scalar(std::stoi(cmd[i][9]), std::stoi(cmd[i][10]), std::stoi(cmd[i][11])));
            circleLayers.push_back(c);
        }
        else if (cmd[i][0] == "rectangle")
        {
            Rectangle r(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), std::stoi(cmd[i][6]), cv::Scalar(std::stoi(cmd[i][7]), std::stoi(cmd[i][8]), std::stoi(cmd[i][9])), cv::Scalar(std::stoi(cmd[i][10]), std::stoi(cmd[i][11]), std::stoi(cmd[i][12])));
            rectangleLayers.push_back(r);
        }
        if (cmd[i][0] == "ligne")
        {
            Ligne l(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), cv::Scalar(std::stoi(cmd[i][6]), std::stoi(cmd[i][7]), std::stoi(cmd[i][8])), cv::Scalar(std::stoi(cmd[i][9]), std::stoi(cmd[i][10]), std::stoi(cmd[i][11])));
            lineLayers.push_back(l);
        }
        if (cmd[i][0] == "triangle")
        {
            Triangle t(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), cv::Scalar(std::stoi(cmd[i][6]), std::stoi(cmd[i][7]), std::stoi(cmd[i][8])), cv::Scalar(std::stoi(cmd[i][9]), std::stoi(cmd[i][10]), std::stoi(cmd[i][11])));
            triangleLayers.push_back(t);
        }
    }

    for (int i = 0; i < circleLayers.size(); i++)
    {
        layers.push_back(&circleLayers[i]);
    }
    for (int i = 0; i < rectangleLayers.size(); i++)
    {
        layers.push_back(&rectangleLayers[i]);
    }
    for (int i = 0; i < lineLayers.size(); i++)
    {
        layers.push_back(&lineLayers[i]);
    }
    for (int i = 0; i < triangleLayers.size(); i++)
    {
        layers.push_back(&triangleLayers[i]);
    }

    //Dessin du contenu du vector
    for (int i = 0; i < layers.size(); ++i)
    {
        layers.at(i)->dessiner(image);
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