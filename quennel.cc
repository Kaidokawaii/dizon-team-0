#include "particle.h"
#include <iostream>
using namespace std;

struct Movement {
	string type = "STREAMER";
	Movement(string new_type) {
		type = new_type;
	}
};

Particle::Particle() {
		x = 0;
		y = 0;
		velocityX = 0;
		veolictyY = 0;
		frames = 0;
}
Particle::Particle(double new_x, double new_y, double new_velocityX, double new_velocityY, double new_frames, Movement new_movementType) {
		x = new_x;
		y = new_y;
		velocityX = new_velocityX;
		velocityY = new_velocityY;
		frames = new_frames;
		movementType = new_movementType;
}
void Particle::set_x(double new_x) {
		x = new_x;
}
void Particle::set_y(double new_y) {
		y = new_y;
}
void Particle::set_velocityX(double new_velocityX) {
		velocityX = new_velocityX;
}
void Particle::set_velocityY(double new_velocityY) {
		velocityY = new_velocityY;
}
void Particle::set_frames(double new_frames) {
		frames = new_frames;
}
void Particle::set_movementType(Movement new_movementType) {
		movementType = new_movementType;
}
double Particle::get_x() const { return x; }

double Particle::get_y() const { return y; }

double Particle::get_velocityX() const { return velocityX; }

double Particle::get_velocityY() const { return velocityY; }

double Particle::get_frames() const { return frames; }

void Particle::physics(Movement& movementType) {
		
}

string Particle::draw(Movement& movementType) {
		return "stub";
}

