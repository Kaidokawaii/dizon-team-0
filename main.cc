#include "particle.h"

using namespace std;

void die(string s) {
	cout << s << endl;
	exit(EXIT_FAILURE);
}

void particleTest() {

}


void graphicsTest() {

}

void systemTest() {

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
		cout << "This will run Ethan's project once it is completed" << endl;	
	} else if (choice == 4) {
		
	} else if (choice == 5) {
		userTests();
	} else {
		die("Bad Value Inputted As Choice");
	}


	return 0;
}
