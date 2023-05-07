#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Forme.h"

//rectangle id x y l w edge_width edge_color fill_color

class Rectangle: public Forme
{
private:
    
    //Largeur du Rectangle
    int width;
    //Hauteur du Rectangle
    int height;

public:

    //Constructeur
    Rectangle(int _x, int _y, int _width, int _height, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color);

    //Getters des variables
    int getHeight() const;
    int getWidth() const;

    //Dessin avec OpenCV
    void dessiner(cv::Mat& image) const override;
};