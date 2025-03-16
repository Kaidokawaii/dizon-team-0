#pragma once
#include <iostream>


struct Movement {
	std::string type;
	Movement(std::string new_type = "STREAMER");
};

class Particle {
	double x;
	double y;
	double velocityX;
	double velocityY;
	double frames; //the lifetime of the particle
	Movement movementType;

	public:
		Particle();
		Particle(double new_x, double new_y, double new_velocityX, double new_velocityY, double new_frames, Movement new_movementType);
		void set_x(double new_x);
		void set_y(double new_y);
		void set_velocityX(double new_velocityX);
		void set_velocityY(double new_velocityY);
		void set_frames(double new_frames);
		void set_movementType(Movement new_movementType);
		double get_x() const;
		double get_y() const;
		double get_velocityX() const;
		double get_velocityY() const;
		double get_frames() const;
		void physics(Movement& movementType);
		std::string draw(Movement& movementType);
};

class Cell {
	private:
		Particle particle;
		Cell* next = nullptr;
		Cell* prev = nullptr;
	public:
		Cell(Particle newParticle);
		Cell* getNext();
		Cell* getPrev();
		Particle getParticle();
		void setNext(Cell* newNext);
		void setPrev(Cell* newPrev);
		void setParticle(Particle newParticle);
};
