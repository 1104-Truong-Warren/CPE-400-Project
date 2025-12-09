#include <iostream>
#include <algorithm>
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
    for(int i=0;i<5;i++)
    {
        Node newNode(i+65);
        nodes.insert(nodes.begin()+i, newNode);
    }
}

void generateEdges(std::vector<Node>& nodes)
{
    //cout<<"Total number of nodes: "<<nodes.size()<<'\n';
    for(int i=0;i<nodes.size();i++)
    {
        //cout<<"Node "<<nodes[i].getId()<<" num edges: "<<nodes[i].getEdges().size()<<'\n';
        std::vector<Node> tempNodes=nodes;
        tempNodes.erase(tempNodes.begin()+i);
        for(int j=0;j<4;j++) //Creating 4 edges per node, and each node should not have more than 4
        {
            if(nodes[i].getEdges().size()< 4 && tempNodes.size()>0)
            {
                
                int randNode=rand()%tempNodes.size(); //Selecting random node
                int randWeight=rand()%7 + 1; //Creating a random weight
                

                //First, create an edge from current node to random and add it to the current
                Node* destNode=&tempNodes[randNode];
                string edgeID1;
                edgeID1+=nodes[i].getId();
                edgeID1+=tempNodes[randNode].getId();
                Edge newEdge1(edgeID1, randWeight, destNode);
                nodes[i].addEdge(newEdge1);

                //cout<<"Edge1 "<<newEdge1.getID()<<":\n"<<newEdge1.getWeight()<<'\n';

                //Then, create an edge from that randomly chosen node to the current node and add it to the randomly chosen node
                string edgeID2;
                edgeID2+=tempNodes[randNode].getId();
                edgeID2+=nodes[i].getId();
                Edge newEdge2(edgeID2, randWeight, &nodes[i]);

                int actualPos=-1;
                for(int k=0;k<nodes.size();k++)
                {
                    if(nodes[k].getId()==tempNodes[randNode].getId())
                    {
                        actualPos=k;
                    }
                }
                nodes[actualPos].addEdge(newEdge2);

                tempNodes.erase(tempNodes.begin()+randNode);

                //cout<<"Edge2 "<<newEdge2.getID()<<":\n"<<newEdge2.getWeight()<<'\n';
            }
        }
    }
}

bool containsNoOverlaps(Node currentNode, Node check)
{
    std::vector currentEdges=currentNode.getEdges();
    cout<<"Checking "<<currentNode.getId()<<"'s edges against "<<check.getId()<<'\n';
    if(currentEdges.size()>0)
    {
        for(int k=0;k<currentEdges.size();k++)
        {
            cout<<"Edge "<<currentEdges[k].getID()<<" vs "<<check.getId()<<'\n';
            if(currentEdges[k].getDest()->getId()!=check.getId())
            {
                cout<<"No overlap\n";
                return true;
            }
        }
    }
    

    cout<<"Overlap\n";
    return false;
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