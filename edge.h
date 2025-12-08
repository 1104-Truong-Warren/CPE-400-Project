#ifndef EDGE_H
#define EDGE_H

#include <string>
using namespace std;

class Edge
{
    private:
        string id;
        int weight;
        char src;
        char dest;
    public:
        Edge();
        Edge(string i, int wei, char s, char d);
        Edge(const Edge& rhs);

        string getID();
        void setID(string i);

        char getSrc();
        void setSrc(char s);

        char getDest();
        void setDest(char d);
        
        int getWeight();
        void setWeight(int wei);
};

#endif