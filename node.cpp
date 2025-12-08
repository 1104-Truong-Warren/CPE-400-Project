#include "node.h"

Node::Node(){ //treated as an error detection
		//defualt node name
		id = '?';
		//buffer, routingTable and edges are all of size 0
		mode = Err;
}
Node::Node(char id, std::vector<Edge> ed) //needs to be workshoped
	: id(id){
	// buffer starts at size() == 0.
	
	// copy all the values into this routingTable
	//call function to setUp my routing table
	//copy all the values into this edges
	edges = ed;
	mode = setUp;
	flag = false; 

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
	
}
void Node::advertiseRtToNeigbors(){

}