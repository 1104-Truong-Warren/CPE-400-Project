#ifndef DATAGRAM_H
#define DATAGRAM_H

#include <string>
//#include "node.h"
class Node;
using namespace std;

enum flagEnum:char{WEIGHT_CHANGE='w', EDGE_CHANGE='e', ROUTE_DISCOVERY='r', NORMAL='n'};
class Datagram
{
    private:
        string id;
        Node* src;
        Node* dest;
        flagEnum flag;
        int hopCount;
        int weightChange;
        bool routerFlag; //Set by the router sending a flag during a state where routing tables are being updated
    public:
        Datagram();
        Datagram(string i, Node* s, Node* d, flagEnum fl);
        Datagram(const Datagram& rhs);

        string getID();
        void setID(string i);

        Node* getSrc();
        void setSrc(Node* s);

        Node* getDest();
        void setDest(Node* d);

        flagEnum getFlag();
        void setFlag(flagEnum fl);

        int getHopCount();
        void incrementHopCount();
};

#endif