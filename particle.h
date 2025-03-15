#pragma once

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
		void setParticle(particle newParticle);
}
