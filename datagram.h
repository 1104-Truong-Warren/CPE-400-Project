#ifndef DATAGRAM_H
#define DATAGRAM_H

#include <string>
#include "node.h"
using namespace std;

enum flagEnum:char{WEIGHT_CHANGE='w', EDGE_CHANGE='e', ROUTE_DISCOVERY='r', NORMAL='n', ERROR='z'};
class Datagram
{
    private:
        string id;
        Node* src;
        Node* dest;
        char flag;
        int hopCount;
    public:
        Datagram();
        Datagram(string i, Node* s, Node* d, flagEnum fl, int hop);
        Datagram(const Datagram& rhs);

        string getID();
        void setID(string i);

        Node* getSrc();
        void setSrc(Node* s);

        Node* getDest();
        void setDest(Node* d);

        char getFlag();
        void setFlag(char fl);

        int getHopCount();
        void setHopCount(int hop);
};

#endif