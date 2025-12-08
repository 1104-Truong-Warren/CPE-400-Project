#ifndef DATAGRAM_H
#define DATAGRAM_H

#include <string>
//#include "node.h"
class Node;
using namespace std;

enum flagEnum:char{EDGE_CHANGE='e', ROUTE_CHANGE='r', NORMAL='n'};
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
        Datagram(string i, Node* s, Node* d, int wei, flagEnum fl, bool rfl);
        Datagram(const Datagram& rhs);

        string getID();
        void setID(string i);

        Node* getSrc();
        void setSrc(Node* s);

        Node* getDest();
        void setDest(Node* d);

        flagEnum getFlag();
        void setFlag(flagEnum fl);

        int getWeightChange();
        void setWeightChange(int wei);

        int getHopCount();
        void incrementHopCount();

        bool getRouterFlag();
        void setRouterFlag(bool rfl);
};

#endif