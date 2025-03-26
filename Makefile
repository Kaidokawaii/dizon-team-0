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
quennel_screenSaver.o: quennel_screenSaver.cc particle.h quennel_screenSaver.h
	g++ -g -c -fsanitize=address -std=c++23 quennel_screenSaver.cc
ethanProjec.o: ethanProjec.cc particle.h ethanProjec.h
	g++ -g -c -fsanitize=address -std=c++23 ethanProjec.cc
Khai_project.o: khaiProject.cc particle.h khai_project.h 
	g++ -g -c -fsanitize=address -std=c++23 khai_project.cc
clean:
	rm -f *.o a.out
