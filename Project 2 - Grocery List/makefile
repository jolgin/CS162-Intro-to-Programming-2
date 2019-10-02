list: main.o menuFunction.o inputValidation.o List.o Item.o
	g++ main.o menuFunction.o inputValidation.o List.o Item.o -o list

main.o: main.cpp
	g++ -c main.cpp

inputValidation.o: inputValidation.hpp inputValidation.cpp
	g++ -c inputValidation.cpp

menuFunction.o: menuFunction.hpp menuFunction.cpp
	g++ -c menuFunction.cpp

List.o: List.hpp List.cpp
	g++ -c List.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

clean:
	rm *.o list 
	 
