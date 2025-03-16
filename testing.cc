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
	return 0;
}
