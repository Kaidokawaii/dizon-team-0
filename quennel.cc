include "particle.h"
using namespace std;

struct Movement {

};

class Particle {
	double position;
	double velocity;
	double frames; //the lifetime of the particle

	Particle() {

	}
	Particle(double new_position, double new_velocity, double new_frames) {

	}
	void set_position(double new_position) {

	}
	void set_velocity(double new_velocity) {

	}
	void set_frames(double new_frames) {

	}
	double get_position() const { return 1; }
	
	double get_velocity() const { return 1; }

	double get_frames() const { return 1; }

	double physics_method(Movement& particle) {
		return 1;
	}

	string draw_method(Movement& particle) {
		return "stub";
	}



};
