#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Forme.h"
class Triangle: public Forme {
private: 
	int width; // longueur de la base 

public:
	//constructeur 
	Triangle(int _x, int _y, int _width, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color);

	//getters des variables 
	int getWidth() const;
	
	//desssin avec opencv
	void dessiner(cv::Mat& image) const override;

};
