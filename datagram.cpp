#include "datagram.h"


Datagram::Datagram()
{
   id="ERROR";
   src=NULL;
   dest=NULL;
   flag=ERROR;
   hopCount=0;
}


Datagram::Datagram(string i, Node* s, Node* d, flagEnum fl)
{
   id=i;
   src=s;
   dest=d;
   flag=fl;
}


Datagram::Datagram(const Datagram& rhs)
{
   id=rhs.id;
   src=rhs.src;
   dest=rhs.dest;
   hopCount=rhs.hopCount;
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


char Datagram::getFlag()
{
   return flag;
}


void Datagram::setFlag(char fl)
{
   flag=fl;
}


int Datagram::getHopCount()
{
   return hopCount;
}


void Datagram::setHopCount(int hop)
{
   hopCount=hop;
}
