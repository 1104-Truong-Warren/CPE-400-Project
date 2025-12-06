graph: main.o
	g++ main.o -o graph
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o graph