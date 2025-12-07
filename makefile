graph: main.o datagram.o edge.o
	g++ main.o datagram.o edge.o -o graph

main.o: main.cpp
	g++ -c main.cpp

datagram.o: datagram.h datagram.cpp
	g++ -c datagram.cpp

edge.o: edge.h edge.cpp
	g++ -c edge.cpp

clean:
	rm *.o graph