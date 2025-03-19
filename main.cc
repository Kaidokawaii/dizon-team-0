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



int main() {
	int choice = 0;
	cout << "Please Enter a Choice:" << endl;
	cout << "1) Run Khai's Project" << endl;
	cout << "2) Run Quennel's Project" << endl;
	cout << "3) Run Ethan's Project" << endl;
	cout << "4) Run Testes" << endl;

	cin >> choice;

	if (!cin) {
		die("Failed To Read Value From Choices");
	} else if (choice == 1) {
		
	} else if (choice == 2) {
		
	} else if (choice == 3) {

	} else if (choice == 4) {
		
	} else {
		die("Bad Value Inputted As Choice");
	}


	return 0;
}
