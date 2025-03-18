a.out: kaiSystem.o kaiGraphics.o testing.o ethan.o quennel.o particle.h
	g++ -g -fsanitize=address testing.o kaiSystem.o kaiGraphics.o ethan.o quennel.o
testing.o: testing.cc particle.h
	g++ -g -c -fsanitize=address testing.cc
kaiSystem.o: kaiSystem.cc particle.h
	g++ -g -c -fsanitize=address kaiSystem.cc
ethan.o: ethan.cc particle.h
	g++ -g -c -fsanitize=address ethan.cc
kaiGraphics.o: kaiGraphics.cc particle.h
	g++ -g -c -fsanitize=address kaiGraphics.cc
quennel.o: quennel.cc particle.h
	g++ -g -c -fsanitize=address quennel.cc
