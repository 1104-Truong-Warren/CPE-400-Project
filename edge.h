#ifndef EDGE_H
#define EDGE_H

#include <string>
class Node;
using namespace std;

class Edge
{
    private:
        string id;
        int weight;
        //Pointer to source is implied by the node who owns the particular instance of edge
        Node* dest;
    public:
        Edge();
        Edge(string i, int wei, Node* d);
        Edge(const Edge& rhs);

        string getID();
        void setID(string i);

        Node* getDest();
        void setDest(Node* d);
        
        int getWeight();
        void setWeight(int wei);
};

#endif