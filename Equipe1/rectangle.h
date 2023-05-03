#pragma one
#include <iostream>

class Rectangle {
private:
	int x, y; //Position du centre de la figure
	int l, w; //Longeur et largeur du rectangle
	int edge_width;
	std::string edge_color;
	std::string fill_color;
public:
	Rectangle(int edge_width, std::string edge_color, std::string fill_color);
	Dessiner();
};