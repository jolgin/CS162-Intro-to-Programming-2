game: main.o Barbarian.o BlueMen.o Creature.o HarryPotter.o Medusa.o Vampire.o inputValidation.o menuFunction.o CreatureQueue.o Tournament.o LoserNode.o LoserQueue.o
	g++ main.o Barbarian.o BlueMen.o Creature.o HarryPotter.o Medusa.o Vampire.o inputValidation.o menuFunction.o CreatureQueue.o Tournament.o LoserNode.o LoserQueue.o -g -o game

main.o: main.cpp
	g++ -c -g main.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c -g  Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c -g BlueMen.cpp

Creature.o: Creature.hpp Creature.cpp
	g++ -c -g Creature.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c -g  HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c -g Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c -g Vampire.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c -g inputValidation.cpp

menuFunction.o: menuFunction.cpp menuFunction.hpp
	g++ -c -g menuFunction.cpp

CreatureQueue.o: CreatureQueue.cpp CreatureQueue.hpp
	g++ -c -g CreatureQueue.cpp

Tournament.o: Tournament.cpp Tournament.hpp
	g++ -c -g Tournament.cpp

LoserNode.o: LoserNode.cpp LoserNode.hpp
	g++ -c -g LoserNode.cpp

LoserQueue.o: LoserQueue.cpp LoserQueue.hpp
	g++ -c -g LoserQueue.cpp 


clean:
	rm *.o game 
