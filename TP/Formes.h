#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Formes {
public:
	virtual ~Formes() {}
	// Méthodes virtuelles pures pour les getters de chaque variable
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual int getR() const = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual int getEdge_width() const = 0;
	virtual cv::Scalar getEdge_color() const = 0;
	virtual cv::Scalar getFill_color() const = 0;

	// Méthode virtuelle pure pour dessiner la forme
	virtual void dessiner(cv::Mat& image) const = 0;
};