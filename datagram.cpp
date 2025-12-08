#include "datagram.h"

Datagram::Datagram()
{
    id="ERROR";
    src=NULL;
    dest=NULL;
    hopCount=0;
    weightChange=-1;
    routerFlag=false;
}

Datagram::Datagram(string i, Node* s, Node* d, int wei, flagEnum fl, bool rfl)
{
    id=i;
    src=s;
    dest=d;
    weightChange=wei;
    flag=fl;
    routerFlag=rfl;
}
Datagram::Datagram(string i, Node* s, Node* d, flagEnum fl, std::vector<std::vector<char>> newDat)
{
    id=i;
    src=s;
    dest=d;
    flag=fl;
    data=newDat;
}

Datagram::Datagram(const Datagram& rhs)
{
    id=rhs.id;
    src=rhs.src;
    dest=rhs.dest;
    flag=rhs.flag;
    hopCount=rhs.hopCount;
    routerFlag=rhs.routerFlag;
}

string Datagram::getID()
{
    return id;
}

void Datagram::setID(string i)
{
    id=i;
}

Node* Datagram::getSrc()
{
    return src;
}

void Datagram::setSrc(Node* s)
{
    src=s;
}

Node* Datagram::getDest()
{
    return dest;
}

void Datagram::setDest(Node* d)
{
    dest=d;
}

flagEnum Datagram::getFlag()
{
    return flag;
}

void Datagram::setFlag(flagEnum fl)
{
    flag=fl;
}

int Datagram::getWeightChange()
{
    return weightChange;
}

void Datagram::setWeightChange(int wei)
{
    weightChange=wei;
}

int Datagram::getHopCount()
{
    return hopCount;
}

void Datagram::incrementHopCount()
{
    hopCount++;
}

bool Datagram::getRouterFlag()
{
    return routerFlag;
}

void Datagram::setRouterFlag(bool rfl)
{
    routerFlag=rfl;
std::vector<std::vector<char>> Datagram::getData(){
    return data;
}
void Datagram::setData(std::vector<std::vector<char>> newDat){
    data = newDat;
}