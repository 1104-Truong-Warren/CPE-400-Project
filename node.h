#ifndef NODE_H
#define NODE_H
#include <vector>
#include "edge.h"
#define MAXSIZE 50
#define MAXBUFFERSIZE 32
class Node{
	private:
		char id;
		int buffer[MAXBUFFERSIZE];
		int routingTable[MAXSIZE][MAXSIZE];
		int routingTableX;
		int routingTAbleY;
		Edge edges[];
	public:
		Node();
};
#endif