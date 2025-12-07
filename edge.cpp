#include "edge.h"

Edge::Edge()
{
    weight=-1;
    id="ERROR";
    dest=NULL;
}

Edge::Edge(string i, int wei, Node* d)
{
    id=i;
    weight=wei;
    dest=d;
}

Edge::Edge(const Edge& rhs)
{
    id=rhs.id;
    weight=rhs.weight;
    dest=rhs.dest;
}

string Edge::getID()
{
    return id;
}

void Edge::setID(string i)
{
    id=i;
}


Node* Edge::getDest()
{
    return dest;
}
void Edge::setDest(Node* d)
{
    dest=d;
}

int Edge::getWeight()
{
    return weight;
}

void Edge::setWeight(int wei)
{
    weight=wei;
}