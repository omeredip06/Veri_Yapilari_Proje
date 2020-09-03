programcalistir:olustur execalistir

olustur: main
	g++  ./lib/main.o -o ./bin/main

main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	
execalistir:
	./bin/main.exe