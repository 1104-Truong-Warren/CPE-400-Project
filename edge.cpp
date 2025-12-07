#include "edge.h"

Edge::Edge()
{
    weight=-1;
    id="ERROR";
    src='y';
    dest='z';
}

Edge::Edge(string i, int wei, char s, char d)
{
    id=i;
    weight=wei;
    src=s;
    dest=d;
}

Edge::Edge(const Edge& rhs)
{
    id=rhs.id;
    weight=rhs.weight;
    src=rhs.src;
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

char Edge::getSrc()
{
    return src;
}

void Edge::setSrc(char s)
{
    src=s;
}

char Edge::getDest()
{
    return dest;
}
void Edge::setDest(char d)
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