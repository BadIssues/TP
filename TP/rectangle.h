#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Formes.h"

//Rectangle id x y width height edge_width edge_color fill_color

class Rectangle : public Formes
{
private:
    // Les variables du rectangle :

    // Positions du rectangle:
    int x; 
    int y; 

    
    // Largeur et longueur du rectangle:
    int width; 
    int height;

    // taille de la bordure du rectangle:
    int edge_width;

    // Couleur de la bordure du rectangle:
    cv::Scalar edge_color;

    // Couleur de remplisage du rectangle:
    cv::Scalar fill_color;

public:
    // Constructeur
    Rectangle(int x_, int y_, int width_, int height_, int edge_width_, cv::Scalar edge_color_, cv::Scalar fill_color_);

    //Getters des variables
    int getX() const;
    int getY() const;
    int getHeight() const;
    int getWidth() const;
    int getEdge_width() const;
    cv::Scalar getEdge_color() const;
    cv::Scalar getFill_color() const;

    //Méthode pour dessiner avec OpenCV :
    void dessiner(cv::Mat& image) const;

};