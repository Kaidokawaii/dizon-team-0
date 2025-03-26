<<<<<<< HEAD
<<<<<<< HEAD
a.out: kaiSystem.o kaiGraphics.o main.o ethan.o quennel.o quennel_screenSaver.o particle.h quennel_screenSaver.h
	g++ -g -fsanitize=address -std=c++23 main.o kaiSystem.o kaiGraphics.o ethan.o quennel.o quennel_screenSaver.o
=======
a.out: kaiSystem.o kaiGraphics.o main.o ethan.o quennel.o ethanProjec.o particle.h ethanProjec.h
	g++ -g -fsanitize=address -std=c++23 main.o kaiSystem.o kaiGraphics.o ethan.o ethanProjec.o quennel.o
>>>>>>> 6f6ac9f269e2eb6eabb7a03caee75391290c7050
=======
a.out: kaiSystem.o kaiGraphics.o main.o ethan.o quennel.o ethanProjec.o khai_project.o particle.h ethanProjec.h khai_project.h
	g++ -g -fsanitize=address -std=c++23 main.o kaiSystem.o kaiGraphics.o ethan.o ethanProjec.o quennel.o khai_project.o
>>>>>>> khai_project
main.o: main.cc particle.h
	g++ -g -c -fsanitize=address -std=c++23 main.cc
testing.o: testing.cc particle.h
	g++ -g -c -fsanitize=address -std=c++23 testing.cc
kaiSystem.o: kaiSystem.cc particle.h
	g++ -g -c -fsanitize=address -std=c++23 kaiSystem.cc
ethan.o: ethan.cc particle.h
	g++ -g -c -fsanitize=address -std=c++23 ethan.cc
kaiGraphics.o: kaiGraphics.cc particle.h
	g++ -g -c -fsanitize=address -std=c++23 kaiGraphics.cc
quennel.o: quennel.cc particle.h
	g++ -g -c -fsanitize=address -std=c++23 quennel.cc
<<<<<<< HEAD
quennel_asteroid.o: quennel_screenSaver.cc particle.h quennel_screenSaver.h
	g++ -g -c -fsanitize=address -std=c++23 quennel_screenSaver.cc
=======
ethanProjec.o: ethanProjec.cc particle.h ethanProjec.h
	g++ -g -c -fsanitize=address -std=c++23 ethanProjec.cc
<<<<<<< HEAD
>>>>>>> 6f6ac9f269e2eb6eabb7a03caee75391290c7050
=======
Khai_project.o: khaiProject.cc particle.h khai_project.h 
	g++ -g -c -fsanitize=address -std=c++23 khai_project.cc
>>>>>>> khai_project
clean:
	rm -f *.o a.out
