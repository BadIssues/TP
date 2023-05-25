#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Forme.h"

class Ligne : public Forme
{
private:

	//Longueur de la Ligne
	int length;

public:

	//Constructeur
	Ligne(int _x, int _y, int _length, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color);

	//Getters des variables
	int getLength() const;

	//Dessin avec OpenCV
	void dessiner(cv::Mat& mat) const override;
};
