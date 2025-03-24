#include "particle.h"
#include <iostream>
#include <string>
using namespace std;


Movement::Movement(string new_type) {
	type = new_type;
}

Particle::Particle() : x(0), y(0), velocityX(0), velocityY(0), frames(0), movementType("STREAMER"), R(255), G(255), B(255) {}

Particle::Particle(double x, double y) : x(x), y(y), velocityX(0), velocityY(0), frames(0), movementType("STREAMER"), R(255), G(255), B(255) {}

Particle::Particle(double x, double y, double vx, double vy, double life, Movement m) : x(x), y(y), velocityX(vx), velocityY(vy), frames(life), movementType(m), R(255), G(255), B(255) {}


void Particle::set_x(double new_x) {
		x = new_x;
}
void Particle::set_y(double new_y) {
		y = new_y;
}
void Particle::set_velocityX(double vx) {
		velocityX = vx;
}
void Particle::set_velocityY(double vy) {
		velocityY = vy;
}
void Particle::set_frames(double life) {
		frames = life;
}
void Particle::set_movementType(Movement m) {
		movementType = m;
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
			velocityY += 0.5;
		}
		/*
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
		*/
		if (movementType.type == "FIREWORK" && frames <= 1) {
			Particle* p1 = new Particle(x, y, -1, 1, 20, Movement("STREAMER"));
			p1->setColor(R,G,B);
			Particle* p2 = new Particle(x, y, 1, -1, 20, Movement("STREAMER"));
			p2->setColor(R,G,B);
			Particle* p3 = new Particle(x, y, -1, -1, 20, Movement("STREAMER"));
			p3->setColor(R,G,B);
			Particle* p4 = new Particle(x, y, 1, 1, 20, Movement("STREAMER"));
			p4->setColor(R,G,B);

			if (owner) {
				owner->add(p1);
				owner->add(p2);
				owner->add(p3);
				owner->add(p4);
			}
		}
		frames--;
}

void Particle::setColor(int r, int g, int b) {
	R = r; G = g; B = b;
}

int Particle::getR() const {
	return R;
}

int Particle::getG() const {
	return G;
}

int Particle::getB() const {
	return B;
}

