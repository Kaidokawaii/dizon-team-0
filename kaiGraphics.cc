#include "particle.h"
#include <iostream>


using namespace std;

ParticleGraphics::ParticleGraphics() : R(255), G(255), B(255) {}

int ParticleGraphics::getColorR() {
	return R;
}
int ParticleGraphics::getColorG() {
	return G;
}
int ParticleGraphics::getColorB() {
	return B;
}

void ParticleGraphics::setColor(int newR, int newG, int newB) {
	R = newR;
	G = newG;
	B = newB;
}

void ParticleGraphics::drawPoint(double x, double y) {
	setbgcolor(R, G, B);
	movecursor(x, y);
	cout << " ";
	cout.flush();
	resetcolor();
	//cout << "Drawing point at: " << x << "," << y << endl;
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
