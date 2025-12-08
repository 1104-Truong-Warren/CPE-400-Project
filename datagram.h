#ifndef DATAGRAM_H
#define DATAGRAM_H

#include <vector>
#include <string>
#include "node.h"
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
        std::vector<std::vector<char>> data;
    public:
        Datagram();
        Datagram(string i, Node* s, Node* d, flagEnum fl);
        Datagram(string i, Node* s, Node* d, flagEnum fl, std::vector<std::vector<char>> newDat);
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

        std::vector<std::vector<char>> getData();
        void setData(std::vector<std::vector<char>> newDat);//acts as a copyier
};

#endif