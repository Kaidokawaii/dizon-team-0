#include "particle.h"
#include "ethanProjec.h"
#include <cassert>

using namespace std;

void die(string s) {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

void cellTest() {
	Particle* p = new Particle(1,1,1,1,1,Movement("STREAMER"));
	Particle* p2 = new Particle(2,2,2,2,2,Movement("FIREWORK"));

	Cell* C = new Cell(p2);
	Cell* C2 = new Cell(p);

	assert(C->getNext() == nullptr);
	assert(C->getPrev() == nullptr);
	assert(C2->getNext() == nullptr);
	assert(C2->getPrev() == nullptr);
	assert(C->getParticle() == p2);
	assert(C2->getParticle() == p);

	C->setNext(C2);
	C2->setPrev(C);


	assert(C->getNext() == C2);
	assert(C->getPrev() == nullptr);
	assert(C2->getNext() == nullptr);
	assert(C2->getPrev() == C);
	delete p;
	delete p2;
	delete C;
	delete C2;
}

void particleTest() {
	Particle* p3 = new Particle(1,2);
	Particle* p4 = new Particle(1,2,3,4,5,Movement("BALLISTIC"));
	
	assert(p3->get_x() == 1);
	assert(p3->get_y() == 2);
	assert(p3->get_velocityX() == 0);
	assert(p3->get_velocityY() == 0);
	assert(p3->get_frames() == 0);
	assert(p3->get_movementType() == "STREAMER");

	assert(p4->get_x() == 1);
	assert(p4->get_y() == 2);
	assert(p4->get_velocityX() == 3);
	assert(p4->get_velocityY() == 4);
	assert(p4->get_frames() == 5);
	assert(p4->get_movementType() == "BALLISTIC");

	p3->set_x(25);
	p3->set_y(16);
	p3->set_velocityX(9);
	p3->set_velocityY(4);
	p3->set_frames(1);
	p3->set_movementType(Movement("FIREWORK"));

	assert(p3->get_x() == 25);
	assert(p3->get_y() == 16);
	assert(p3->get_velocityX() == 9);
	assert(p3->get_velocityY() == 4);
	assert(p3->get_frames() == 1);
	assert(p3->get_movementType() == "FIREWORK");

	delete p3;
	delete p4;
}


void systemTest() {
	const auto [rows, cols] = get_terminal_size();
	ParticleSystem PS(cols, rows);
//	ParticleGraphics graph;

	Particle* p5 = new Particle(1,2);
	Particle* p6 = new Particle(1,2,3,4,5,Movement("BALLISTIC"));
	Particle* p7 = new Particle(13,2,7,1,9,Movement("STREAMER"));
	Particle* p8 = new Particle(18,24,32,54,52,Movement("FIREWORK"));


	
	
	assert(PS.numParticles() == 0);
	PS.add(p5);
	assert(PS.numParticles() == 1);
	PS.add(p6);
	assert(PS.numParticles() == 2);
	PS.add(p7);
	assert(PS.numParticles() == 3);
	PS.add(p8);
	assert(PS.numParticles() == 4);

	PS.moveParticles();


	assert(p5->get_x() == 1);
	assert(p5->get_y() == 2);
	assert(p5->get_velocityX() == 0);
	assert(p5->get_velocityY() == 0);
	assert(p5->get_frames() == -1);
	assert(p5->get_movementType() == "STREAMER");



	assert(p6->get_x() == 4);
	assert(p6->get_y() == 6);
	assert(p6->get_velocityX() == 3);
	assert(p6->get_velocityY() == 4.5);
	assert(p6->get_frames() == 4);
	assert(p6->get_movementType() == "BALLISTIC");

	assert(p7->get_x() == 20);
	assert(p7->get_y() == 3);
	assert(p7->get_velocityX() == 7);
	assert(p7->get_velocityY() == 1);
	assert(p7->get_frames() == 8);
	assert(p7->get_movementType() == "STREAMER");


	//p8 is deleted b/c out of range

	//assert(p8->get_x() == 50);
	//assert(p8->get_y() == 78);
	//assert(p8->get_velocityX() == 32);
//	assert(p8->get_velocityY() == 54);
//	assert(p8->get_frames() == 51);
//	assert(p8->get_movementType() == "FIREWORK");

	

}

void userTests() {
	const auto [rows, cols] = get_terminal_size();
	ParticleSystem u(cols, rows);
	ParticleGraphics g;

	int choice = 0;
	while (true) {
		cout << "Enter a Choice:" << endl;
		cout << "1) Add A Particle To The System" << endl;
		cout << "2) Draw All The Particles" << endl;
		cout << "3) Run Physics On The Particles" << endl;
		cout << "4) Quit" << endl;

		cin >> choice;

		if (!cin) {
			die("Failed To Read From UserTesting Choices");
		} else if (choice == 1) {
			double x = 0;
			double y = 0;
			double dx = 0;
			double dy = 0;
			double life = 0;
			Movement m;

			int moveChoice = 0;

			cout << "Enter an X position between 0 and " << cols << endl;
			cin >> x;
			if (!cin) { die("Failed To Read X Position");}

			cout << "Enter an Y position between 0 and " << rows << endl;
			cin >> y;
			if (!cin) { die("Failed To Read Y Position");}

			cout << "Enter an X velocity" << endl;
			cin >> dx;
			if (!cin) { die("Failed To Read X velocity");}

			cout << "Enter an Y velocity" << endl;
			cin >> dy;
			if (!cin) { die("Failed To Read Y velocity");}

			cout << "Enter a lifetime of the particle:" << endl;
			cin >> life;
			if (!cin) {die("Failed to read particle lifetime");}
			if (life <= 0) {die("Particle lifetime must be greater than zero!");}

			cout << "Enter a movement type (Enter 1 for STREAMER, 2 for BALLISTIC, 3 for FIREWORK)" << endl;
			cin >> moveChoice;
			if (!cin) {die("Failed to read movement type");}
			if (moveChoice != 1 && moveChoice != 2 && moveChoice != 3) {die("Invalid Input for Movement Type!");}

			if (moveChoice == 1) {
				m.type = "STREAMER";
			} else if (moveChoice == 2) {
				m.type = "BALLISTIC";
			} else {
				m.type = "FIREWORK";
			}

			Particle* newP = new Particle(x,y,dx,dy,life,m);
			u.add(newP);


		} else if (choice == 2) {
			clearscreen();
			u.drawParticles(g);
			cout << endl;

		} else if (choice == 3) {
			u.moveParticles();
		} else if (choice == 4) {
			break;
		}
	}
}

int main() {
	int choice = 0;
	cout << "Please Enter a Choice:" << endl;
	cout << "1) Run Khai's Project" << endl;
	cout << "2) Run Quennel's Project" << endl;
	cout << "3) Run Ethan's Project" << endl;
	cout << "4) Run Simulated Tests" << endl;
	cout << "5) Run Tests Yourself" << endl;

	cin >> choice;

	if (!cin) {
		die("Failed To Read Value From Choices");
	} else if (choice == 1) {
		cout << "This will run Khai's project once it is completed" << endl;	
	} else if (choice == 2) {
		cout << "This will run Quennel's project once it is completed" << endl;
	} else if (choice == 3) {
		ethanProject();
	} else if (choice == 4) {
		cout << "Calling All Tests..." << endl;
		cellTest();		
		cout << "Cell Class Tests Passed!" << endl;
		particleTest();		
		cout << "Particle Class Tests Passed!" << endl;
		systemTest();		
		cout << "Particle System Class Tests Passed!" << endl;
	} else if (choice == 5) {
		userTests();
	} else {
		die("Bad Value Inputted As Choice");
	}


	return 0;
}
