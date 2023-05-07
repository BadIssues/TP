#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Forme
{
private:

	//Position de la Forme
	int x;
	int y;
	//Epaisseur du bord
	int edge_width;
	//Couleur du bord
	cv::Scalar edge_color;
	//Couleur de remplissage
	cv::Scalar fill_color;

public:

	//Constructeur
    Forme(int _x, int _y, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color);

	//Getters des variables
	int getX() const;
	int getY() const;
	int getEdge_width() const;
	cv::Scalar getEdge_color() const;
	cv::Scalar getFill_color() const;

	//Dessin avec OpenCV
	virtual void dessiner(cv::Mat& mat) const = 0;
};