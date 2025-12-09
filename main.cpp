#include <iostream>
#include "edge.h"
#include "datagram.h"
#include "node.h"
//#include "display.h"
using namespace std;

void generateNodes(std::vector<Node>& nodes);
void generateEdges(std::vector<Node>& nodes);
bool containsNoOverlaps(Node currentNode, Node check);
void printEdges(std::vector<Node> nodes);

int main(int argc, char* argv[]) {
    string a="aba";
    a+="ba\n";
    //cout<<a;

    std::vector<Node> nodes;
    generateNodes(nodes);
    generateEdges(nodes);
    printEdges(nodes);
    priority_queue<Datagram, vector<Datagram>, less<Datagram>> datagramsToSend; //Priority queue of datagrams, smallest delay time in front
    
    //cout << "This is MyProject" << endl;
    return 0;
}

void generateNodes(std::vector<Node>& nodes)
{
    for(int i=0;i<20;i++)
    {
        Node newNode(i+65);
        nodes.insert(nodes.begin()+i, newNode);
    }
}

void generateEdges(std::vector<Node>& nodes)
{
    for(int i=0;i<nodes.size();i++)
    {
        for(int j=0;j<4;j++) //Creating 4 edges per node, and each node should not have more than 4
        {
            if(nodes[i].getEdges().size()!= 4)
            {
                int randNode=random()%nodes.size(); //Selecting random node
                int randWeight=random()%7 + 1; //Creating a random weight
                while(randNode==i && containsNoOverlaps(nodes[i], nodes[randNode]))
                {
                    randNode=random()%nodes.size();
                } //Making sure the function doesn't try to make an edge from a node to itself

                //First, create an edge from current node to random and add it to the current
                Node* destNode=&nodes[randNode];
                string edgeID1;
                edgeID1+=nodes[i].getId();
                edgeID1+=nodes[randNode].getId();
                Edge newEdge1(edgeID1, randWeight, destNode);
                nodes[i].addEdge(newEdge1);

                //Then, create an edge from that randomly chosen node to the current node and add it to the randomly chosen node
                string edgeID2;
                edgeID2+=nodes[randNode].getId();
                edgeID2+=nodes[i].getId();
                Edge newEdge2(edgeID2, randWeight, &nodes[i]);
                nodes[randNode].addEdge(newEdge2);
            }
        }
    }
}

bool containsNoOverlaps(Node currentNode, Node check)
{
    std::vector currentEdges=currentNode.getEdges();
    for(int i=0;i<currentEdges.size();i++)
    {
        if(currentEdges[i].getDest()->getId() == check.getId())
        {
            return false;
        }
    }

    return true;
}

void printEdges(std::vector<Node> nodes)
{
    for(int i=0;i<nodes.size();i++)
    {
        std::vector<Edge> currentEdges=nodes[i].getEdges();
        cout<<"Node "<<nodes[i].getId()<<":\n";
        for(int j=0;j<currentEdges.size();j++)
        {
            cout<<currentEdges[j].getID()<<'\n';
        }
        cout<<"----------------\n";
    }
}