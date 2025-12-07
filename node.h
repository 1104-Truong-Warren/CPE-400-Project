#ifndef NODE_H
#define NODE_H
#include <vector>
#define MAXSIZE 50
#define MAXBUFFERSIZE 32
class Node{
	private:
		char id;
		int buffer[MAXBUFFERSIZE];
		int routingTable[MAXSIZE][MAXSIZE];
		int routingTableX;
		int routingTAbleY;

		//Edges[200] edges;
	public:
		Node();
};
#endif