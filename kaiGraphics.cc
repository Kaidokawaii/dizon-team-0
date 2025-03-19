#include "particle.h"
#include <iostream>
#include <string>
#include <iostream>
#include <sys/ioctl.h>
#include <utility>
using namespace std;

//Usage:
//Echo RED as part of a cout to turn the following text red
//Echo RESET after you are done and it will go back to normal
//For example: cout << RED << "Hello World" << RESET << endl;
const string RESET   = "\033[0m";
const string BLACK   = "\033[30m";      // Black 
const string RED     = "\033[31m";      // Red 
const string GREEN   = "\033[32m";      // Green
const string YELLOW  = "\033[33m";      // Yellow
const string BLUE    = "\033[34m";      // Blue 
const string MAGENTA = "\033[35m";      // Magenta
const string CYAN    = "\033[36m";      // Cyan 
const string WHITE   = "\033[37m";      // White
const string BOLDBLACK   = "\033[1m\033[30m";      // Bold Black
const string BOLDRED     = "\033[1m\033[31m";      // Bold Red 
const string BOLDGREEN   = "\033[1m\033[32m";      // Bold Green 
const string BOLDYELLOW  = "\033[1m\033[33m";      // Bold Yellow 
const string BOLDBLUE    = "\033[1m\033[34m";      // Bold Blue 
const string BOLDMAGENTA = "\033[1m\033[35m";      // Bold Magenta 
const string BOLDCYAN    = "\033[1m\033[36m";      // Bold Cyan 
const string BOLDWHITE   = "\033[1m\033[37m";      // Bold White

//Sets the background color for all text printed from this point on
//Values range from 0 to 255 in each color channel
void setbgcolor(uint8_t R, uint8_t G, uint8_t B) {
    std::cerr << "\x1b[48;2;" << (int)R << ";" << (int)G << ";" << (int)B << "m";
}

//Sets the foreground color for all text printed from this point on
void setcolor(uint8_t R, uint8_t G, uint8_t B) {
    std::cerr << "\x1b[38;2;" << (int)R << ";" << (int)G << ";" << (int)B << "m";
}

//Sets the foreground and background colors back to the default
void resetcolor() {
    std::cerr << "\x1b[0m";
}

//These functions are like a mini NCURSES library

//Returns the ROWS and COLS of the current terminal
std::pair<int,int> get_terminal_size() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return {w.ws_row-1, w.ws_col}; //Subtract 1 to give room for the UNIX prompt at the bottom of the screen
}

//Moves the cursor to the indicated row and column
void movecursor(uint32_t row, uint32_t col) {
    std::cerr << "\033[" << row << ";" << col << "H";
}

//Clears the screen
void clearscreen() {
    std::cerr << "\033[2J";
}

//copied from colors.h in the colors_demo directory instead of doing #include (dont need to go back and forth for colors)

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
	movecursor(static_cast<int>(x), static_cast<int>(y));
	cout << " ";
	resetcolor();
	cout.flush();
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
