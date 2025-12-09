#include "datagram.h"

Datagram::Datagram()
{
    id="ERROR";
    src=NULL;
    dest=NULL;
    forwardDest=NULL;
    hopCount=0;
    delay=-1;
    routerFlag=false;
}

Datagram::Datagram(string i, Node* s, Node* d, int del, flagEnum fl, bool rfl, std::vector<std::vector<char>> newDat)
{
    id=i;
    src=s;
    dest=d;
    delay=del;
    flag=fl;
    routerFlag=rfl;
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

int Datagram::getDelay()
{
    return delay;
}

void Datagram::setDelay(int del)
{
    delay=del;
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
}

std::vector<std::vector<char>> Datagram::getData(){
    return data;
}

void Datagram::setData(std::vector<std::vector<char>> newDat){
    data = newDat;
}

Datagram Datagram::operator<(Datagram rhs)
{
    if(delay<rhs.delay)
    {
        return *this;
    }
    return rhs;
}