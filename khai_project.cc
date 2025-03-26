#include "khai_project.h"
#include <unistd.h>
#include <cstdlib>

void particleCollision(ParticleSystem& system) {
	Cell* current = system.getHead();
	while (current) {
		Particle* p1 = current->getParticle();
		Cell* other = current->getNext();

		while (other) {
			Particle* p2 = other->getParticle();

			double dx = p1->get_x() - p2->get_x();
			double dy = p1->get_y() - p2->get_y();
			double distance = dx*dx + dy*dy;

			if (distance < 4.0) { //collision
				if (p1->getR() == 255 && p1->getG() == 0 && p1->getB() == 0 &&
					p2->getR() == 0 && p2->getG() == 255 && p2->getB() == 0) {
					p2->setColor(255, 0, 0); //green -> red
				} else if (p1->getR() == 0 && p1->getG() == 255 && p1->getB() == 0 &&
                    p2->getR() == 0 && p2->getG() == 0 && p2->getB() == 255) {
                    p2->setColor(255, 0, 0); //blue -> green
				} else if (p1->getR() == 0 && p1->getG() == 0 && p1->getB() == 255 &&
                    p2->getR() == 255 && p2->getG() == 0 && p2->getB() == 0) {
                    p2->setColor(255, 0, 0); //red -> blue
				}
			}
			other = other->getNext();
		}
		current = current->getNext();
	}
}

void khai_project() {
	auto [rows, cols] = get_terminal_size();
	ParticleSystem system(cols, rows);
	ParticleGraphics graphics;

	for (int i = 0; i <60; i++) {
		Particle* p = new Particle(
				rand() % static_cast<int>(system.get_screenWidth()-2),
				rand() % static_cast<int>(system.get_screenHeight()-2),
				(rand()%5)-2,
				(rand()%5)-2,
				1000,
				Movement("STREAMER")
			);

		if (i < 20) p->setColor(255, 0, 0);
		else if (i < 40) p->setColor(0, 255, 0);
		else p->setColor(0, 0, 255);

		system.add(p);
	}
//animation loop	
	for (int frame = 0; frame < 250; frame++) {
		
		clearscreen();

		particleCollision(system);
		
		system.moveParticles();

		Cell* current = system.getHead();
		while (current) {
			Particle* p = current->getParticle();
			double x = p->get_x(), y = p->get_y();
			double vx = p->get_velocityX();
			double vy = p->get_velocityY();

			if (x <= 0 || x >= system.get_screenWidth()-1) p->set_velocityX(-vx);
			if (y <= 0 || y >= system.get_screenHeight()-1) p->set_velocityY(-vy);

			current = current->getNext();
		}

		//system.drawWindow();
		system.drawParticles(graphics);

		movecursor(0, 0);
		//std::cout << "Frame: " << frame << "/100 - Particles: " << system.numParticles();
		//std::cout.flush();

		usleep(80000);
	}
}
