#ifndef NODE_H
#define NODE_H

#include <vector>
#include "edge.h"
#define MAXNODES 50
#define MAXEDGES 5
#define MAXBUFFERSIZE 32
#define INF 1000000
class Node{
	private:
		char id;
		//Packet buffer[MAXBUFFERSIZE];
		int bufferCount; 
		int routingTable[MAXNODES][MAXNODES];
		int routingTableN;
		Edge edges[MAXEDGES];
		int numEdges; 
	public:
		Node();
		Node(char id, int bufferCount, int routingTable[MAXNODES][MAXNODES], int routingTableN, Edge edges[MAXEDGES], int numEdges);
		Node(const Node& rhs); 

		
};
#endif