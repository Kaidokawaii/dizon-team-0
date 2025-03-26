a.out: kaiSystem.o kaiGraphics.o main.o ethan.o quennel.o quennel_screenSaver.o particle.h quennel_screenSaver.h
	g++ -g -fsanitize=address -std=c++23 main.o kaiSystem.o kaiGraphics.o ethan.o quennel.o quennel_screenSaver.o
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
quennel_asteroid.o: quennel_screenSaver.cc particle.h quennel_screenSaver.h
	g++ -g -c -fsanitize=address -std=c++23 quennel_screenSaver.cc
clean:
	rm -f *.o a.out
