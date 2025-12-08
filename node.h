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
		std::vector<std::vector<char>> routingTable;
		//int routingTableN;
		//Edge edges[MAXEDGES];
		std::vector<Edge> edges;

		int mode; 
		bool flag;// internal flag that gets checked with the Datagram flag. 
		//
	public:
		Node();
		Node(char id,std::vector<Edge> ed);
		Node(const Node& rhs); 
		
		//getters
		const char getId();
		const std::vector<Datagram>& getBuffer() const;
		const Datagram& getButterAt(int i) const;

		const std::vector<std::vector<char>>& getRoutingTable() const;

		const std::vector<Edge>& getEdges() const;
		const Edge& getEdgeAt(int i) const;

		//setters
		void bufferEnque();
		Datagram bufferDeque();

		void buildInitalRoutingTable();
		void advertiseRtToNeigbors();


		
		
		//note before a router does something it must check if there has been a chn age in its routing table. 
		//setters
		//functons that repesent 
		//weightChangeNotify()
		//

		
};
#endif