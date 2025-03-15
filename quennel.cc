include "particle.h"
using namespace std;

struct Movement {
	string type = "STREAMER";
	Movement(string new_type) {
		type = new_type;
	}
};

class Particle {
	double x;
	double y;
	double velocityX;
	double velocityY;
	double frames; //the lifetime of the particle
	Movement movementType;

public: 
	double
	Particle() {
		x = 0;
		y = 0;
		velocityX = 0;
		veolictyY = 0;
		frames = 0;
	}
	Particle(double new_x, double new_y, double new_velocityX, double new_velocityY, double new_frames, Movement new_movementType) {
		x = new_x;
		y = new_y;
		velocityX = new_velocityX;
		velocityY = new_velocityY;
		frames = new_frames;
		movementType = new_movementType;
	}
	void set_x(double new_x) {
		x = new_x;
	}
	void set_y(double new_y) {
		y = new_y;
	}
	void set_velocityX(double new_velocityX) {
		velocityX = new_velocityX;
	}
	void set_velocityY(double new_velocityY) {
		velocityY = new_velocityY;
	}
	void set_frames(double new_frames) {
		frames = new_frames;
	}
	void set_movementType(Movement new_movementType) {
		movementType = new_movementType;
	}
	double get_x() const { return x; }

	double get_y() const { return y; }

	double get_velocityX() const { return velocityX; }

	double get_velocityY() const { return velocityY; }

	double get_frames() const { return frames; }

	void physics(Movement& movementType) {
		
	}

	string draw(Movement& movementType) {
		return "stub";
	}



};
