#include "particle.h"
#include <iostream>
using namespace std;

ParticleGraphics::ParticleGraphics() : color("Default Color") {}

string ParticleGraphics::getColor() {
	return color;
}

void ParticleGraphics::setColor(string color) {
	this->color = color;
}

void ParticleGraphics::drawPoint(double x, double y) {
	cout << "Drawing point at: " << x << "," << y << endl;
}

void ParticleGraphics::drawRectangle(double x, double y, double width, double height) {
	cout << "Drawing Rectangle at (" << x << ", " << y << ") and size: " << width << "x" << height << endl;
}

void ParticleGraphics::drawOval(double x, double y, double width, double height) {
    cout << "Drawing Oval at (" << x << ", " << y << ") and size: " << width << "x" << height << endl;
}

void ParticleGraphics::drawPolygon(vector<double> points) { //fix for pairs
	cout << "Drawing Polygon at points: ";
		for (const auto &point : points) {
			cout << point << " ";
		}
		cout << endl;
}

void ParticleGraphics::drawLine(double x1, double y1, double x2, double y2) {
	cout << "Drawing a line at: " << x1 << "," << y1 << " to " << x2 << "," << y2 << endl;
}
