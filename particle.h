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
	double x, y;
	double velocityX, velocityY;
	double frames; //the lifetime of the particle
	Movement movementType;
	int R, G, B;

public:
		//Constructors
		Particle();
		Particle(double x, double y);
		Particle(double x, double y, double vx, double vy, double life, Movement m);
		
		//Physics Methods
		void physics(ParticleSystem *owner);
		
		//Position Getters and Setters
		double get_x() const;
		double get_y() const;
		void set_x(double new_x);
		void set_y(double new_y);

		//Velocity Getters and Setters
		double get_velocityX() const;
		double get_velocityY() const;
		void set_velocityX(double vx);
		void set_velocityY(double vy);
		
		//Lifetime manegment
		double get_frames() const;
		void set_frames(double life);
		
		//Movement Type
		std::string get_movementType() const;
		void set_movementType(Movement m);
		
		//Color Management
		void setColor(int r, int g, int b);
		int getR() const;
		int getG() const;
		int getB() const;
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
		double screenWidth, screenHeight;
		Cell* head;
		Cell* tail;

	public:
		Cell* getHead() const { return head; }
		ParticleSystem(double width, double height);
		~ParticleSystem(); //Destructor
		void add(Particle* particle);
		int numParticles();
		void moveParticles();
		void drawParticles(ParticleGraphics& graphics);
		void drawWindow();
		double get_screenWidth() const; //columns
		double get_screenHeight() const; //rows
		void deleteQParticle();
		void deleteParticle(Cell* current); //deletes given particle
		void ethanProjectDelete();
};

#endif
