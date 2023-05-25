#include "pch.h"
#include "Parseur.h"
#include "../TP/Cercle.h"
#include "../TP/Ligne.h"
#include "../TP/Rectangle.h"
#include "../TP/Triangle.h"

Forme* Parseur::parse(const std::string& description)
{
    // Code de parsing pour identifier la forme et ses paramètres
    if (description == "cercle")
    {
        return new Cercle(0, 0, 0, 0, cv::Scalar(), cv::Scalar());
    }
    else if (description == "ligne")
    {
        return new Ligne(0, 0, 0, 0, cv::Scalar(), cv::Scalar());
    }
    else if (description == "rectangle")
    {
        return new Rectangle(0, 0, 0, 0, 0, cv::Scalar(), cv::Scalar());
    }
    else if (description == "triangle")
    {
        return new Triangle(0, 0, 0, 0, cv::Scalar(), cv::Scalar());
    }

    // Si la forme n'est pas reconnue, retourner nullptr
    return nullptr;
}
