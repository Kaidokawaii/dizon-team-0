#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H
#include <iostream>
#include <string>
#include <vector>
#include "/public/colors.h"

struct Movement {
public:
	std::string type;
	Movement(std::string new_type = "STREAMER");
};

class ParticleSystem;

class Particle {
public:
	double x;
	double y;
	double velocityX;
	double velocityY;
	double frames; //the lifetime of the particle
	Movement movementType;

		Particle();
		Particle(double x, double y);
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
		std::string get_movementType() const;
		void physics(ParticleSystem *owner);
		std::string draw();
};

class ParticleGraphics {
	public:
        int R;
        int G;
        int B;

        ParticleGraphics();
        int getColorR();
        int getColorG();
        int getColorB();
        void setColor(int newR, int newG, int newB);

        void drawPoint(double x, double y);
        void drawRectangle(double x, double y, double width, double height);
        void drawOval(double x, double y, double width, double height);
        void drawPolygon(std::vector<double> points);
        void drawLine(double x1, double y1, double x2, double y2);

        void drawP(Particle& particle);
        //void moveP(Particle& particle);
};


class Cell {
	public:
		Particle* particle;
		Cell* next = nullptr;
		Cell* prev = nullptr;

		Cell(Particle* newParticle);
		Cell* getNext();
		Cell* getPrev();
		Particle* getParticle();
		void setNext(Cell* newNext);
		void setPrev(Cell* newPrev);
		void setParticle(Particle* newParticle);
};

class ParticleSystem {
public:
		double screenWidth, screenHeight;
		Cell* head;
		Cell* tail;

		ParticleSystem(double width, double height);
		~ParticleSystem(); //Destructor
		void add(Particle* particle);
		int numParticles();
		void moveParticles();
		void drawParticles(ParticleGraphics& graphics);
		void drawWindow();
		double get_screenWidth() const; //columns
		double get_screenHeight() const; //rows
};

#endif
