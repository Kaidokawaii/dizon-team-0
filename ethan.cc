#include "particle.h"
#include <iostream>

using namespace std;

Cell::Cell(Particle newParticle) {
	particle = newParticle;
}
Cell* Cell::getNext() {
	return next;
}
Cell* Cell::getPrev() {
	return prev;
}
Particle Cell::getParticle() {
	return particle;
}
void Cell::setNext(Cell* newNext) {
	next = newNext;
}
void Cell::setPrev(Cell* newPrev) {
	prev = newPrev;
}


