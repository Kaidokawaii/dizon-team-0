#include "particle.h"
#include <iostream>

using namespace std;

ParticleSystem::ParticleSystem(double width, double height) : screenWidth(width), screenHeight(height), head(nullptr), tail(nullptr) {}

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
		count++;
		current = current->getNext();
	}
	return count;
}

void ParticleSystem::moveParticles() {
	Cell* current = head;
	while (current) {
		current->getParticle()->physics(this);
		current = current->getNext();
	}
}

void ParticleSystem::drawParticles(ParticleGraphics& graphics) {
	Cell* current = head;
	while (current) {
		graphics.drawP(*current->getParticle());
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
