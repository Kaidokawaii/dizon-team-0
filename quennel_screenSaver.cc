#include <iostream>
#include "particle.h"
#include "quennel_screenSaver.h"
#include "/public/colors.h"
using namespace std;

void quennel_project() {	
	auto [rows,cols] = get_terminal_size();
	rows--;
	cols--;

	ParticleGraphics pg;
	ParticleSystem ps(cols,rows);
	//int count = 0;
	clearscreen();
	//setbgcolor(255,165,0);
	//count = ps.numParticles();

	for (int frame = 0; frame <= 100; frame++) {
		pg.setColor(rand() % 256, rand() % 256, rand() % 256);
		clearscreen();
		ps.deleteQParticle();
		for (int i = 0; i < 2; i++) {
			int x = rand() % cols;
			int y = rand() % rows;
			int dx = 0;
			int dy = 0;
			int posdx = rand() % 2;
			int posdy = rand() % 2;
			if (posdx == 0) {
				dx = 1;
			}
			else if (posdx == 1) {
				dx = -1;
			}
			if (posdy == 0) {
				dy = 1;
			}
			else if (posdy == 1) {
				dy = -1;
			}
			int frames = rand() % 4;

			Particle* p = new Particle(x,y,dx,dy,frames,Movement("FIREWORK"));
			ps.add(p);
			//count++;

			ps.moveParticles();
			if (y == 0) {
				p->set_frames(0);
			}
			ps.deleteQParticle();
			ps.drawParticles(pg);

		}
		usleep(100'000);

	}

	clearscreen();

}


