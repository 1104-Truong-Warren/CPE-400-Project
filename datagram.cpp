#include "datagram.h"

Datagram::Datagram()
{
    id="ERROR";
    src='y';
    dest='z';
}

Datagram::Datagram(string i, char s, char d)
{
    id=i;
    src=s;
    dest=d;
}

Datagram::Datagram(const Datagram& rhs)
{
    id=rhs.id;
    src=rhs.src;
    dest=rhs.dest;
}

string Datagram::getID()
{
    return id;
}

void Datagram::setID(string i)
{
    id=i;
}

char Datagram::getSrc()
{
    return src;
}

void Datagram::setSrc(char s)
{
    src=s;
}

char Datagram::getDest()
{
    return dest;
}

void Datagram::setDest(char d)
{
    dest=d;
}