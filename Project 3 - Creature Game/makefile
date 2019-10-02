game: main.o Barbarian.o BlueMen.o Creature.o HarryPotter.o Medusa.o Vampire.o inputValidation.o menuFunction.o CreatureQueue.o Tournament.o
	g++ main.o Barbarian.o BlueMen.o Creature.o HarryPotter.o Medusa.o Vampire.o inputValidation.o menuFunction.o CreatureQueue.o Tournament.o -o game

main.o: main.cpp
	g++ -c main.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

Creature.o: Creature.hpp Creature.cpp
	g++ -c Creature.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c inputValidation.cpp

menuFunction.o: menuFunction.cpp menuFunction.hpp
	g++ -c menuFunction.cpp

CreatureQueue.o: CreatureQueue.cpp CreatureQueue.hpp
	g++ -c CreatureQueue.cpp

Tournament.o: Tournament.cpp Tournament.hpp
	g++ -c Tournament.cpp

clean:
	rm *.o game 
