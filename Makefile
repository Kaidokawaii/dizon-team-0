a.out: kaiSystem.o kaiGraphics.o main.o ethan.o quennel.o ethanProjec.o khai_project.o particle.h ethanProjec.h khai_project.h
	g++ -g -fsanitize=address -std=c++23 main.o kaiSystem.o kaiGraphics.o ethan.o ethanProjec.o quennel.o khai_project.o
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
ethanProjec.o: ethanProjec.cc particle.h ethanProjec.h
	g++ -g -c -fsanitize=address -std=c++23 ethanProjec.cc
Khai_project.o: khaiProject.cc particle.h khai_project.h 
	g++ -g -c -fsanitize=address -std=c++23 khai_project.cc
clean:
	rm -f *.o a.out
