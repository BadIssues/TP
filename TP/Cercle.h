#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Forme.h"

//cercle id x y r edge_width edge_color fill_color

class Cercle: public Forme
{
private:

	//Rayon du Cercle
	int r;

public:

	//Constructeur
	Cercle(int _x, int _y, int _r, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color);

	//Getters des variables
	int getR() const;

	//Dessin avec OpenCV
	void dessiner(cv::Mat& mat) const override;
};
