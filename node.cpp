#include "node.h"

Node::Node(){ //treated as an error detection
		//defualt node name
		id = '?';
		//buffer, routingTable and edges are all of size 0
		mode = Err;
}
Node::Node(char id) //needs to be workshoped , std::vector<Edge> ed
	: id(id){
	// buffer starts at size() == 0.
	
	// copy all the values into this routingTable
	//call function to setUp my routing table
	//copy all the values into this edges
	//edges = ed;
	mode = setUp;
	flag = false; 
	//buildInitalRoutingTable();

}
Node::Node(const Node& rhs)
    : id(rhs.id),
      mode(rhs.mode)
	{
	//copy all the values into the buffer
	buffer = rhs.buffer;
	//copy all the values into the routing table
	routingTable = rhs.routingTable;
	//copy all the values into the edges
	edges = rhs.edges;
}

const char Node::getId(){
	return id;
}
const std::queue<Datagram>& Node::getBuffer() const{
	return buffer; 
}
const std::vector<std::vector<char>>& Node::getRoutingTable() const{
	return routingTable;
}

void Node::addEdge(Edge& newEdge)
{
	if(edges.size()<4)
	{
		edges.insert(edges.begin()+edges.size(), newEdge);
	}
	
	if(edges.size()==4)
	{
		//buildInitalRoutingTable();
		//Resulting in a segmentation fault at the moment
	}
}

const std::vector<Edge>& Node::getEdges() const{
	return edges;
}
const Edge& Node::getEdgeAt(int i) const{
	return edges[i];
}

//setters
void Node::bufferEnque(const Datagram& d) {
	buffer.push(d);
}

Datagram Node::bufferDeque() {
	if (buffer.empty()) {
		throw std::runtime_error("Buffer is empty");
	}
	Datagram d = buffer.front();
	buffer.pop();
	return d;
}

bool Node::isEmpty() const {
	return buffer.empty();
}

void Node::buildInitalRoutingTable(){
	//note for this to work, edges must be predefined
	//check iff we have edges
	if(edges.size()>0){
		routingTable.resize(edges.size());// makes one row for every edge to a neighbor
		for(int i = 0; i < 3; i++){
			routingTable[i].resize(3);// make 3 colms,
			//each row is a route entry for a neigboring row. 
			//1st colm is the id of the node, 2nd colum is the total cost to get to the node 3rd colum is the id of next hop node to follow this route
		}
		for(int i = 0; i < routingTable.size(); i++){
			routingTable[i][0] = edges[i].getDest()->getId(); 
		}
		for(int i = 0; i < 3; i++){
			routingTable[i][1] = edges[i].getWeight();
		}
		for(int i = 0; i < 3; i++){
			routingTable[i][2] = edges[i].getDest()->getId();
		}
	}
}
void Node::advertiseRtToNeigbors(){
	//send a data gram to node 
	// the datagram needs to hold my routing table and the source of routing table. 
}