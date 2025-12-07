#include "node.h"

Node::Node(){
		id = '?'; //defualt node name
		//Packet buffer[MAXBUFFERSIZE];
		bufferCount = -1;
		//initatlize the routing table with infinity
		for(int i = 0; i < MAXNODES; i++ ){ 
			for(int j = 0; j < MAXNODES; j++){
				routingTable[i][j] = INF;
			}
		}
		routingTableN = -1;
		numEdges = -1; 
}
Node::Node(char id, int bufferCount, int routingTable[MAXNODES][MAXNODES], int routingTableN, Edge edges[MAXEDGES], int numEdges)
	: id(id), 
	bufferCount(bufferCount), 
	routingTableN(routingTableN), 
	numEdges(numEdges){

	for(int i = 0; i < routingTableN; i++ ){ 
		for(int j = 0; j < routingTableN; j++){
			this->routingTable[i][j] = routingTable[i][j];
		}
	}
	for(int i = 0; i < numEdges; i++){
		this->edges[i] = edges[i];
	}	
}
Node::Node(const Node& other)
    : id(other.id),
      bufferCount(other.bufferCount),
      routingTableN(other.routingTableN),
      numEdges(other.numEdges)
{
    for (int i = 0; i < routingTableN; i++) {
        for (int j = 0; j < routingTableN; j++) {
            this->routingTable[i][j] = other.routingTable[i][j];
        }
    }

    for (int i = 0; i < numEdges; i++) {
        this->edges[i] = other.edges[i];
    }
}
