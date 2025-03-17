#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <string>
#include <vector>

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
	Particle* next;

	public:
		Particle();
		Particle(double x, double y);
		Particle(double new_x, double new_y, double new_velocityX, double new_velocityY, double new_frames, Movement new_movementType);
		void set_x(double new_x);
		void set_y(double new_y);
		void set_velocityX(double new_velocityX);
		void set_velocityY(double new_velocityY);
		void set_frames(double new_frames);
		void set_movementType(Movement new_movementType);
		void move();
		void draw();
		
		double get_x() const;
		double get_y() const;
		double get_velocityX() const;
		double get_velocityY() const;
		double get_frames() const;
		std::string get_movementType() const;
		void physics(Movement& movementType);
		//std::string draw(Movement& movementType);
};

class Cell {
	private:
		Particle* particle;
		Cell* next = nullptr;
		Cell* prev = nullptr;
	public:
		Cell(Particle* newParticle);
		Cell* getNext();
		Cell* getPrev();
		Particle* getParticle();
		void setNext(Cell* newNext);
		void setPrev(Cell* newPrev);
		void setParticle(Particle* newParticle);
};

class ParticleSystem {
	private:
		double screenWidth, screenHeight;
		Cell* head;
		Cell* tail;

	public: 
		ParticleSystem(double width, double height);
		~ParticleSystem(); //Destructor
		void add(Particle* particle);
		int numParticles();
		void moveParticles();
		void drawParticles();
		void drawWindow();
};

class ParticleGraphics {
	private:
		std::string color;
	public:
		ParticleGraphics();
		std::string getColor();
		void setColor(std::string color);
		void drawPoint(double x, double y);
		void drawRectangle(double x, double y, double width, double height);
		void drawOval(double x, double y, double width, double height);
		void drawPolygon(std::vector<double> points);
		void drawLine(double x1, double y1, double x2, double y2);

};

#endif
