all:derle bagla calistir
derle:
	gcc -c -I "./include" ./src/main.c -o ./lib/main.o
	gcc -c -I "./include" ./src/FileReader.c -o ./lib/FileReader.o
	gcc -c -I "./include" ./src/Flea.c -o ./lib/Flea.o
	gcc -c -I "./include" ./src/Insect.c -o ./lib/Insect.o
	gcc -c -I "./include" ./src/Plant.c -o ./lib/Plant.o
	gcc -c -I "./include" ./src/Living.c -o ./lib/Living.o
	gcc -c -I "./include" ./src/Mosquito.c -o ./lib/Mosquito.o
	gcc -c -I "./include" ./src/Habitat.c -o ./lib/Habitat.o
	gcc -c -I "./include" ./src/Simulation.c -o ./lib/Simulation.o
bagla:
	gcc ./lib/main.o ./lib/FileReader.o ./lib/Flea.o ./lib/Insect.o ./lib/Plant.o ./lib/Living.o ./lib/Mosquito.o ./lib/Habitat.o ./lib/Simulation.o -o ./bin/program
calistir:
	./bin/program.exe