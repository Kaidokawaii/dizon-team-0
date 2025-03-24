#include "particle.h"
#include <unistd.h>
#include <iostream>
using namespace std;

int main() {
	auto [rows, cols] = get_terminal_size();
	ParticleSystem system(cols, rows);
    ParticleGraphics graphics;

    // Create test particles
    Particle* streamer = new Particle(10, 10, 1, 0, 100, Movement("STREAMER"));
    streamer->setColor(0, 0, 255); // Blue

    Particle* ballistic = new Particle(30, 5, 0, -2, 100, Movement("BALLISTIC"));
    ballistic->setColor(0, 255, 0); // Green

    Particle* firework = new Particle(20, 50, 0, -3, 5, Movement("FIREWORK"));
    firework->setColor(255, 0, 0); // Red

    system.add(streamer);
    system.add(ballistic);
    system.add(firework);

    // Animation loop
    for (int i = 0; i < 100; i++) {
		clearscreen();

		system.drawWindow();
		system.moveParticles();
		system.drawParticles(graphics);

		movecursor(0, 0);
		cout << "Particles: " << system.numParticles() << "     ";
		cout.flush();

        usleep(500000); // 100ms delay
    }

    return 0;
}
