graph: main.o datagram.o edge.o node.o display.o
	g++ main.o datagram.o edge.o node.o display.o -o graph $(shell pkg-config --libs sfml-graphics sfml-window sfml-system)

main.o: main.cpp
	g++ -std=c++17 -c main.cpp $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)

node.o: node.h node.cpp
	g++ -std=c++17 -c node.cpp $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)

datagram.o: datagram.h datagram.cpp
	g++ -std=c++17 -c datagram.cpp $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)

edge.o: edge.h edge.cpp
	g++ -std=c++17 -c edge.cpp $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)

display.o: display.h display.cpp
	g++ -std=c++17 -c display.cpp $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)

clean:
	rm -f *.o graph
