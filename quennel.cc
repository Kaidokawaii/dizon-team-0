#include "particle.h"
#include <iostream>
#include <string>
using namespace std;


Movement::Movement(string new_type) {
	type = new_type;
}

Particle::Particle() {
		Movement m("STREAMER");
		x = 0;
		y = 0;
		velocityX = 0;
		velocityY = 0;
		frames = 0;
		movementType = m;
}

Particle::Particle(double x, double y) : x(x), y(y), velocityX(0), velocityY(0), frames(0), movementType("STREAMER") {}

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

string Particle::get_movementType() const { return movementType.type;}
	
void Particle::physics(ParticleSystem *owner = nullptr) {		
		x += velocityX;
		y += velocityY;
		if (movementType.type == "BALLISTIC") {
			velocityY += 1;
		}	
		if (movementType.type == "FIREWORK") {
			if (frames == 0) {
				Particle *p1 = new Particle(x,y,-1*velocityX,velocityY,2.0,Movement("STREAMER"));	
				Particle *p2 = new Particle(x,y,velocityX,-1*velocityY,2.0,Movement("STREAMER"));	
				Particle *p3 = new Particle(x,y,-1*velocityX,-1*velocityY,2.0,Movement("STREAMER"));	
				Particle *p4 = new Particle(x,y,velocityX,velocityY,2.0,Movement("STREAMER"));	
				if (owner) {
					owner->add(p1);
					owner->add(p2);
					owner->add(p3);
					owner->add(p4);
				}
			}
		}
		frames--;
}
//testing git push
//test: writing on git hub
string Particle::draw() {
		return "stub";
}


