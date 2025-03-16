#include <iostream>
#include "particle.h"

using namespace std;

int main() {
	Movement m("FIREWORK");
	Particle p1;
	double a,b,c,d;
	a = 5;
	b = 12;
	c = 3;
	d = 16;
	Particle p2(a, b, c, d,2, m);

	cout << "Particle 1 Values Are: " << p1.get_x() << " " << p1.get_y() << " " << p1.get_velocityX() << " " << p1.get_velocityY() << " " << p1.get_frames() << " " << endl;
	cout << "Particle 2 Values Are: " << p2.get_x() << " " << p2.get_y() << " " << p2.get_velocityX() << " " << p2.get_velocityY() << " " << p2.get_frames() << " " << endl;


	Cell A(p1);
	Cell B(p2);

	A.setNext(&B);
	B.setPrev(&A);
	if (A.getPrev()) {
		cout << "A points BEFORE itself towards " << A.getPrev() << endl;
	} else {
		cout << "A points BEFORE itself towards Null Pointer" << endl;
	}

	if (A.getNext()) {
		cout << "A points AFTER itself towards " << A.getNext() << endl;
	} else {
		cout << "A points AFTER itself towards Null Pointer" << endl;
	}

	if (B.getNext()) {
		cout << "B points AFTER itself towards " << B.getNext() << endl;
	} else {
		cout << "B points AFTER itself towards Null Pointer" << endl;
	}

	if (B.getPrev()) {
		cout << "B points BEFORE itself towards " << B.getPrev() << endl;
	} else {
		cout << "B points BEFORE itself towards Null Pointer" << endl;
	}



	//Quennel's test for particle class
	Movement motion("BALLISTIC");
	Particle tt;
	tt.set_movementType(motion);
	tt.set_velocityY(-20);
	tt.set_frames(10);
	cout << "Particle tt's position: (" << tt.get_x() << "," << tt.get_y() << ")" << endl;
	cout << "Particle tt's velocity: (" << tt.get_velocityX() << "," << tt.get_velocityY() << ")" << endl;
	cout << "Particle tt has " << tt.get_frames() << " frames." << endl;
	cout << "Particle tt is " << tt.get_movementType() << endl;

	return 0;
}
