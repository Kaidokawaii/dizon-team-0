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
		if (current->getParticle()) {
			delete current->getParticle();
		}
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
		Particle* particle = current->getParticle();
		particle->physics(this);

	/*	if (particle->get_x() < 0 || particle->get_x() >= screenWidth || particle->get_y() < 0 || particle->get_y() >= screenHeight) { //check for out of bounds
			Cell* next = current->getNext();
			if (current->getPrev()) {
				current->getPrev()->setNext(next);
			} else {
				head = next;
			}
			if (next) {
				next->setPrev(current->getPrev());
			} else {
				tail = current->getPrev();
			}
			delete particle;
			delete current;
			current = next;
		} else {
			current = current->getNext();
		} */
		current = current->getNext();
	}
}

void ParticleSystem::deleteQParticle() {
	Cell* temp = head;
	while (temp) {
		Particle* p = temp->getParticle();
		Cell* cur = temp;
		temp = temp->next;
		/*if (p->get_frames() == 0) {
			deleteParticle(cur);
		}*/
		if (p->get_x() < 0 or p->get_x() >= screenWidth or p->get_y() < 0 or p->get_y() >= screenHeight) {
			deleteParticle(cur);
		}
		else if (p->get_frames() < 0 and p->get_movementType() == "BALLISTIC") {
			deleteParticle(cur);
		}
		else if (p->get_frames() == 0 and p->get_movementType() == "STREAMER") {
			deleteParticle(cur);
		}
	}
void ParticleSystem::ethanProjectDelete() {
	Cell* temp = head;
	while (temp) {
		Particle* p = temp->getParticle();
		Cell* currNode = temp;
		temp = temp->next;
		if (p->get_x() < 0 || p->get_x() >= screenWidth || p->get_y() < 0 || p->get_y() >= screenHeight - 1) { //check for out of bounds
			//cout << "Deleting Particle B/C Out Of Range" << endl;
			deleteParticle(currNode);
		}
	}
}

void ParticleSystem::deleteParticle(Cell* current) {
	if (!head) exit(1);
	if (!(head->getNext())) {
		Cell* temp = head;
		delete temp->getParticle();
		delete temp;
		head = tail = nullptr;
	} 
	else {
		if (current == head) {
			head = head->getNext();
			head->setPrev(nullptr);
			delete current->getParticle();
			delete current;
		}
		else if (current == tail) {
			tail = tail->getPrev();
			tail->setNext(nullptr);
			delete current->getParticle();
			delete current;
		}
		else {
			current->getPrev()->setNext(current->getNext());
			current->getNext()->setPrev(current->getPrev());
			delete current->getParticle();
			delete current;
		}
	}

}

void ParticleSystem::drawParticles(ParticleGraphics& g) {
	Cell* current = head;
	while (current) {
		Particle* p = current->getParticle();
		g.setColor(p->getR(), p->getG(), p->getB());
		g.drawPoint(p->get_x(), p->get_y());
		current = current->getNext();
	}
}

double ParticleSystem::get_screenWidth() const {
	return screenWidth;
}

double ParticleSystem::get_screenHeight() const {
	return screenHeight;
}

void ParticleSystem::drawWindow() {
	ParticleGraphics g;
	g.setColor(255, 255, 255); //set to white for testing

	for (int x = 0; x < screenWidth; x++) { //top and bottom
		g.drawPoint(x, 0);
		g.drawPoint(x, screenHeight-1);
	}
	for (int y = 0; y < screenHeight; y++) { //left right side
		g.drawPoint(0, y);
		g.drawPoint(screenWidth-1, y);
	}
}

