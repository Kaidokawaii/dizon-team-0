#include "particle.h"
#include <iostream>

using namespace std;

//Constructor
Cell::Cell(Particle* newParticle) : particle(newParticle), next(nullptr), prev(nullptr) {}

//Return Next Ptr
Cell* Cell::getNext() {
	return next;
}

//Return Previous Ptr
Cell* Cell::getPrev() {
	return prev;
}

//Return Particle Ptr
Particle* Cell::getParticle() {
	return particle;
}

//Set Next Ptr
void Cell::setNext(Cell* newNext) {
	next = newNext;
}

//Set Previous Ptr
void Cell::setPrev(Cell* newPrev) {
	prev = newPrev;
}

//Set Particle
void Cell::setParticle(Particle* newParticle) {
	particle = newParticle;
}

