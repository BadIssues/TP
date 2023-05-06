#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//cercle id x y r edge_width edge_color fill_color

class Cercle
{
private:

	//Position du Cercle
	int x;
	int y;
	//Rayon du Cercle
	int r;
	//Epaisseur du Cercle
	int edge_width;
	//Couleur du bord
	cv::Scalar edge_color;
	//Couleur de remplissage
	cv::Scalar fill_color;

public:

	Cercle(int _x, int _y, int _r, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color);

	//Getters des variables
	int getX() const;
	int getY() const;
	int getR() const;
	int getEdge_width() const;
	cv::Scalar getEdge_color() const;
	cv::Scalar getFill_color() const;

	//Dessin avec OpenCV
	void dessiner(cv::Mat& mat) const;
};
