a.out: kaiSystem.o kaiGraphics.o main.o ethan.o quennel.o particle.h
	g++ -g -fsanitize=address -std=c++23 main.o kaiSystem.o kaiGraphics.o ethan.o quennel.o
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
clean:
	rm -f *.o a.out
