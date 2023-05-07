#include "Forme.h"
#include <iostream>

Forme::Forme(int _x, int _y, int _edge_width, cv::Scalar _edge_color, cv::Scalar _fill_color)
	: x(_x), y(_y), edge_width(_edge_width), edge_color(_edge_color), fill_color(_fill_color)
{
}

int Forme::getX() const
{
	return x;
}

int Forme::getY() const
{
	return y;
}

int Forme::getEdge_width() const
{
	return edge_width;
}

cv::Scalar Forme::getEdge_color() const
{
	return edge_color;
}

cv::Scalar Forme::getFill_color() const
{
	return fill_color;
}

void Forme::dessiner(cv::Mat& mat) const
{
	std::cout << "Une forme !" << std::endl;
}
