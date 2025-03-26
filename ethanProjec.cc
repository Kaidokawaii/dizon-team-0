#include "particle.h"
#include "ethanProjec.h"
#include "/public/colors.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void ethanProject() {
	srand(time(0));
	const auto [rows, cols] = get_terminal_size();
	ParticleSystem PS(cols-1, rows);
	ParticleGraphics graph;
	

	Particle* p1 = new Particle((rand() % cols) + 1, (rand() % rows) + 1, 1,1,500,Movement("STREAMER"));
	PS.add(p1);

	int particleCount = 5;
	show_cursor(false);
	clearscreen();

	for (int i = 0; i < 100; i++) {
		clearscreen(); 
		
		/*graph.drawRectangle(0,0,cols,1);
		graph.drawRectangle(0,0,1,rows);
		graph.drawRectangle(0,rows,cols,1);
		graph.drawRectangle(cols,0,1,rows);*/


		PS.moveParticles(); //Physics
		PS.ethanProjectDelete(); //Delete Out Of Range Particles
		PS.drawParticles(graph); //Draw Particles
		particleCount = PS.numParticles(); //Keep Track Of Particle Count
		setbgcolor(0,0,204);

		//Run This While Particle Count Is Less Than 20 So There Are Always 20 Particles On Screen
		while (particleCount < 20) {
			int moveChoice = (rand() % 2) + 1;
			bool negx = false;
			bool negy = false;
			if (rand() % 2 == 0) {
				negx = true;
			} 
			if (rand() % 2 == 0) {
				negy = true;
			}
			

			//8 Checks For The 8 Pairs Of Positive And Negative Velocities For X And Y
			if (moveChoice == 1 && negx && negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), -((rand() % 3) + 1), -((rand() % 3) + 1),500,Movement("STREAMER"));
				PS.add(newP);
			} else if (moveChoice == 2 && negx && negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), -((rand() % 3) + 1),-((rand() % 3) + 1),500,Movement("BALLISTIC"));	
				PS.add(newP);
			} if (moveChoice == 1 && !negx && !negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), ((rand() % 3) + 1), ((rand() % 3) + 1),500,Movement("STREAMER"));
				PS.add(newP);
			} else if (moveChoice == 2 && !negx && !negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), ((rand() % 3) + 1),((rand() % 3) + 1),500,Movement("BALLISTIC"));	
				PS.add(newP);
			} else if (moveChoice == 1 && !negx && negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), ((rand() % 3) + 1), -((rand() % 3) + 1),500,Movement("STREAMER"));
				PS.add(newP);
			} else if (moveChoice == 2 && !negx && negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), ((rand() % 3) + 1),-((rand() % 3) + 1),500,Movement("BALLISTIC"));	
				PS.add(newP);
			} if (moveChoice == 1 && negx && !negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), -((rand() % 3) + 1), ((rand() % 3) + 1),500,Movement("STREAMER"));
				PS.add(newP);
			} else if (moveChoice == 2 && negx && !negy) {
				Particle* newP = new Particle((rand() % cols), (rand() % rows), -((rand() % 3) + 1),((rand() % 3) + 1),500,Movement("BALLISTIC"));	
				PS.add(newP);
			}
			particleCount++;
		}
	
		cout.flush();
		

		usleep(100'000);
	}
		setbgcolor(0,0,0);
		clearscreen();
		show_cursor(true);
		cout << endl;

}



//This All Broken Below \/

//int clickedRow, clickedCol = -1;
//bool mouseDown = false;
/*
void ethanProject() {
	srand(time(0));
	const auto [rows, cols] = get_terminal_size();
	ParticleSystem PS(cols-1, rows);
	ParticleGraphics graph;
	
	//Rows - 48, Cols = 139

	atexit(clean);
	set_raw_mode(true);
	show_cursor(false);
	set_mouse_mode(true);
	setbgcolor(0,0,0);
	on_mousedown(mouseHandlerDown);
	on_mouseup(mouseHandlerUp);
	//cout << "Before WHile Loop Hit" << endl;	

	clearscreen();
	while (true) {
		//cout << "start while loop hit" << endl;
		PS.moveParticles();
		PS.ethanProjectDelete();
		PS.drawParticles(graph);
		cout.flush();
		//graph.setColor((rand() % 255), (rand() % 255), (rand() % 255));

		int ch = quick_read();
		if (ch == ERR) {
			//cout << "Do Nothing" << endl;
			//Do Nothing (Means No Input Read)
		}
		if (ch == 'q') {
			//cout << "User Entered Q" << endl;
			break; //Means User Wants To Quit
		}
		if (mouseDown) {
			mouseDown = false;
			if(clickedRow > 0 && clickedCol > 0) {
				Particle* newP = new Particle(clickedRow,clickedCol,0,1,cols - clickedCol - 4, Movement("FIREWORK"));
				PS.add(newP);
				clickedRow = -1;
				clickedCol = -1;
			} else {
				//cout << "Continue Statement Hit" << endl;
				continue;
			}
		}
		clearscreen();
		usleep(100'000);
		//cout << "End Of While Loop Hit" << endl;
	}
	



	cout << "This is temo dialogue dtuff" << endl;
}*/


/*
void mouseHandlerDown(int row, int col) {
	clickedRow = col;
	clickedCol = row;
	mouseDown = true;
	cout << "You Clicked X = " << clickedRow << " and Y = " << clickedCol;
}
void mouseHandlerUp(int row, int col) {
	clickedRow = col;
	clickedCol = row;
	mouseDown = false;
	cout << "You Clicked X = " << clickedRow << " and Y = " << clickedCol;
}

void clean() {
	set_mouse_mode(false); //turns off accepting mouse input
	set_raw_mode(false); //turns off raw mode, basically removes immediate key presses
	show_cursor(true); //shows cursor again
	clearscreen(); //clear everything from screen
	setbgcolor(0,0,0); //set bg color to black
	setcolor(255,255,255); //set text color to white
}

void badExit(int x) {
	exit(0);
}*/
