#include "particle.h"
#include "/public/colors.h"
#include <iostream>
#include <string>
using namespace std;

ParticleGraphics::ParticleGraphics() : R(255), G(255), B(255) {}

string getAnsiColor(int r, int g, int b) {
	if (r > 200 && g < 50 && b < 50) return RED;
    if (g > 200 && r < 50 && b < 50) return GREEN;
    if (b > 200 && r < 50 && g < 50) return BLUE;
    if (r > 200 && g > 200 && b < 50) return YELLOW;
    if (r > 200 && b > 200 && g < 50) return MAGENTA;
    if (g > 200 && b > 200 && r < 50) return CYAN;
    if (r > 200 && g > 200 && b > 200) return WHITE;
    return WHITE; // default
}

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
	::setcolor(newR, newG, newB);
	
	R = newR;
	G = newG;
	B = newB;
}

void ParticleGraphics::drawPoint(double x, double y) {
    if (x<0 || y < 0) return;

	string color = getAnsiColor(R,G,B);

	cerr << color
		 << "\033[" << (int)y+1 << ";" << (int)x+1 << "H"
		 << "█" 
		 << RESET;

    cerr.flush();
}

//WRK This doesn't belong here
/*
void ParticleGraphics::moveP(Particle& particle) {
	particle.physics(particle.movementType);
}
*/

void ParticleGraphics::drawRectangle(double x, double y, double width, double height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			drawPoint(x + j, y + i);
		}
	}
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
