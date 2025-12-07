graph: main.o datagram.o edge.o node.o display.o
	g++ main.o datagram.o edge.o node.o display.o -o graph

main.o: main.cpp
	g++ -c main.cpp

node.o: node.h node.cpp
	g++ -c node.cpp

datagram.o: datagram.h datagram.cpp
	g++ -c datagram.cpp

edge.o: edge.h edge.cpp
	g++ -c edge.cpp

display.o: display.h display.cpp
	g++ -std=c++17 -c display.cpp $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)

clean:
	rm *.o graph