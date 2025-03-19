#include <iostream>
#include "particle.h"

using namespace std;

//Khai's test for Particle System Class
 
void testParticleSystem() {
        ParticleSystem system(1080, 720);
        cout << "Screen size: " << 1080 << "x" << 720 << "\n";

        //Test add function
        Particle* firstP = new Particle(100, 200);
        Particle* secondP = new Particle(150, 250);
        Particle* thirdP = new Particle(200, 300);

        system.add(firstP);
        system.add(secondP);
        system.add(thirdP);

        //Test numParticles function
        cout << "Number of particles: " << system.numParticles() << "\n";

        //Test moveParticles
        system.moveParticles();

        //Test drawParticles
        system.drawParticles();

        //Test drawWindow();
        system.drawWindow();
    }


    void testParticleGraphics() {
        ParticleGraphics graphics;
        graphics.setColor("blue");
        cout << "Current color: " << graphics.getColor() << "\n";

        //Test drawing functions
        graphics.drawPoint(50, 50);
        graphics.drawRectangle(100, 100, 50, 25);
        graphics.drawOval(200, 200, 25, 50);
        graphics.drawPolygon({50, 70, 300, 70}); //fix for coords
        graphics.drawLine(0, 0, 1080, 720);
    }   

int main() {
	Movement m("FIREWORK");
	Particle p1;
	double a = 5, b = 12, c = 3, d = 16;
	Particle p2(a, b, c, d, 2, m);

	cout << "Particle 1 Values Are: " << p1.get_x() << " " << p1.get_y() << " " << p1.get_velocityX() << " " << p1.get_velocityY() << " " << p1.get_frames() << " " << endl;
	cout << "Particle 2 Values Are: " << p2.get_x() << " " << p2.get_y() << " " << p2.get_velocityX() << " " << p2.get_velocityY() << " " << p2.get_frames() << " " << endl;

//Ethan's Test For Cell Class
	Cell A(&p1);
	Cell B(&p2);

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

	//Khai testing functions:
	testParticleSystem();
	testParticleGraphics();

<<<<<<< HEAD




	cout << "1 + 1 = 2 again" << endl;
=======
	cout << "testing and fixing merge conflict" << endl;
>>>>>>> 48ca57fad489d6f25129cfcef81a8e3093b54e8c
	return 0;
}
