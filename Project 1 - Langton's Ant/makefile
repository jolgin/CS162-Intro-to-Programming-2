ant:  main.o  Ant.o menuFunction.o inputValidation.o
	g++ main.o Ant.o menuFunction.o inputValidation.o -o ant 

main.o: main.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

menuFunction.o: menuFunction.cpp menuFunction.hpp
	g++ -c menuFunction.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c inputValidation.cpp

clean:
	rm *.o ant 

