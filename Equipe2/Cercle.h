#pragma once
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//cercle id x y r edge_width edge_color fill_color

class Cercle
{
public:

	//Position du Cercle
	int x;
	int y;
	//Rayon du Cercle
	int r;
	//Epaisseur du Cercle
	int edge_width;
	//Couleur du bord
	std::string edge_color;
	//Couleur de remplissage
	std::string fill_color;

public:

	Cercle(int _x, int _y, int _r, int _edge_width, std::string _edge_color, std::string _fill_color);

	//Getters des variables
	int getX() const;
	int getY() const;
	int getR() const;
	int getEdge_width() const;
	std::string getEdge_color() const;
	std::string getFill_color() const;

	//Dessin avec OpenCV
	void dessiner(cv::Mat& mat) const;
};
