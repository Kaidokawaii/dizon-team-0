#include "particle.h"
#include <iostream>

using namespace std;

ParticleSystem::ParticleSystem(double width, double height) : screenWidth(width), screenHeight(height), head(nullptr), tail(nullptr) {}

//void ParticleSystem::draw() {
//    cout << "Drawing at (" << width << "," << height << ")" << endl;
//}


void ParticleSystem::add(Particle* newParticle) {
	Cell* newCell = new Cell(newParticle);
	if(!head) {
		head = newCell;
		tail = newCell;
	} else {
		newCell->setPrev(tail);
		tail->setNext(newCell);
		tail = newCell;
	}
}

ParticleSystem::~ParticleSystem() {
    Cell* current = head;
    while (current) {
        Cell* next = current->getNext();
        delete current->getParticle();
        delete current;
        current = next;
    }
}

int ParticleSystem::numParticles() {
	int count = 0;
	Cell* current = head;
	while (current) {
		count ++;
		current = current->getNext();
	}
	return count;
}

void ParticleSystem::moveParticles() {
	Cell* current = head;
	while (current) {
		current->getParticle()->moveP();
		current = current->getNext();
	}
}

void ParticleSystem::drawParticles() {
	Cell* current = head;
	while (current) {
		current->getParticle()->drawP();
		current = current->getNext();
	}
}

void ParticleSystem::drawWindow() {
	cout << "Width: " << screenWidth << " Height: " << screenHeight << endl;
}

double ParticleSystem::get_screenWidth() const {
	return screenWidth;
}

double ParticleSystem::get_screenHeight() const {
	return screenHeight;
}
