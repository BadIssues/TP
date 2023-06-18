#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "readFile.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ligne.h"

// Fonction de rappel pour gérer l'événement de clic gauche de la souris
void Souris(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN) {
        // Créer une nouvelle forme par défaut à la position du clic gauche
        cv::Scalar defaultColor(0, 0, 0); // Couleur par défaut (noir)
        std::unique_ptr<Rectangle> r = std::make_unique<Rectangle>(x, y, 50,50,4, defaultColor,defaultColor);
        std::vector<std::unique_ptr<Forme>>& layers = *static_cast<std::vector<std::unique_ptr<Forme>>*>(userdata);
        layers.push_back(std::move(r));
    }
}

int main()
{
    // Déclarer une image OpenCV
    cv::Mat image(cv::Size(400, 400), CV_8UC3, cv::Scalar(255, 255, 255)); // Couleur sous format BGR et non RGB

    // Déclarer un vecteur rassemblant les pointeurs de toutes les formes
    std::vector<std::unique_ptr<Forme>> layers;

    // Lire le fichier texte
    std::vector<std::vector<std::string>> cmd = readFile();

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == "cercle")
        {
            std::unique_ptr<Cercle> c = std::make_unique<Cercle>(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), cv::Scalar(std::stoi(cmd[i][6]), std::stoi(cmd[i][7]), std::stoi(cmd[i][8])), cv::Scalar(std::stoi(cmd[i][9]), std::stoi(cmd[i][10]), std::stoi(cmd[i][11])));
            layers.push_back(std::move(c));
        }
        else if (cmd[i][0] == "rectangle")
        {
            std::unique_ptr<Rectangle> r = std::make_unique<Rectangle>(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), std::stoi(cmd[i][6]), cv::Scalar(std::stoi(cmd[i][7]), std::stoi(cmd[i][8]), std::stoi(cmd[i][9])), cv::Scalar(std::stoi(cmd[i][10]), std::stoi(cmd[i][11]), std::stoi(cmd[i][12])));
            layers.push_back(std::move(r));
        }
        else if (cmd[i][0] == "ligne")
        {
            std::unique_ptr<Ligne> l = std::make_unique<Ligne>(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), cv::Scalar(std::stoi(cmd[i][6]), std::stoi(cmd[i][7]), std::stoi(cmd[i][8])), cv::Scalar(std::stoi(cmd[i][9]), std::stoi(cmd[i][10]), std::stoi(cmd[i][11])));
            layers.push_back(std::move(l));
        }
        else if (cmd[i][0] == "triangle")
        {
            std::unique_ptr<Triangle> t = std::make_unique<Triangle>(std::stoi(cmd[i][2]), std::stoi(cmd[i][3]), std::stoi(cmd[i][4]), std::stoi(cmd[i][5]), cv::Scalar(std::stoi(cmd[i][6]), std::stoi(cmd[i][7]), std::stoi(cmd[i][8])), cv::Scalar(std::stoi(cmd[i][9]), std::stoi(cmd[i][10]), std::stoi(cmd[i][11])));
            layers.push_back(std::move(t));
        }
    }

    //Dessin du contenu du vector
    for (int i = 0; i < layers.size(); ++i)
    {
        layers[i] ->dessiner(image);
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