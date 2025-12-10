#ifndef DATAGRAM_H
#define DATAGRAM_H

#include <vector>
#include <string>
//#include "node.h"
class Node;
using namespace std;

enum flagEnum:char{EDGE_CHANGE='e', ROUTE_CHANGE='r', NORMAL='n', FORWARD='f'};
class Datagram
{
    private:
        string id;
        Node* src;
        Node* dest;
        Node* forwardDest;
        flagEnum flag;
        int hopCount;
        int delay; //Will tell main how long to wait before adding packet to node's buffer queue
        bool routerFlag; //Set by the router sending a flag during a state where routing tables are being updated
        std::vector<std::vector<char> > data;
    public:
        Datagram();
        Datagram(string i, Node* s, Node* d, int del, flagEnum fl, bool rfl, std::vector<std::vector<char> > newDat);
        Datagram(const Datagram& rhs);

        string getID();
        void setID(string i);

        Node* getSrc();
        void setSrc(Node* s);

        Node* getDest();
        void setDest(Node* d);

        flagEnum getFlag();
        void setFlag(flagEnum fl);

        int getDelay();
        void setDelay(int delay);

        int getHopCount();
        void incrementHopCount();

        bool getRouterFlag();
        void setRouterFlag(bool rfl);
        
        std::vector<std::vector<char> > getData();
        void setData(std::vector<std::vector<char> > newDat);//acts as a copier

        Datagram operator<(Datagram rhs); //For use in a priority queue in main
};

#endif