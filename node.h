#ifndef NODE_H
#define NODE_H

#include <vector>
#include "edge.h"
#include "datagram.h"

#define MAXNODES 50
#define MAXEDGES 5
#define MAXBUFFERSIZE 32
#define INF 1000000
enum modes {Normal, setUp, Err};
class Node{
	private:
		char id;
		std::vector<Datagram> buffer;
		//int bufferCount; 
		//int routingTable[MAXNODES][MAXNODES];
		std::vector<std::vector<int>> routingTable;
		//int routingTableN;
		//Edge edges[MAXEDGES];
		std::vector<Edge> edges;

		int mode; 
		bool flag;// internal flag that gets checked with the Datagram flag. 
		//
	public:
		Node();
		Node(char id,std::vector<std::vector<int>> rT,std::vector<Edge> ed, char mode);
		Node(const Node& rhs); 
		
		//getters
		char getId();
		int getBufferCount();

		//setters
		//functons that repesent 
		//weightChangeNotify()
		//

		
};
#endif