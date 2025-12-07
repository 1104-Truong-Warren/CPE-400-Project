#ifndef DATAGRAM_H
#define DATAGRAM_H

#include <string>
using namespace std;

class Datagram
{
    private:
        string id;
        char src;
        char dest;
    public:
        Datagram();
        Datagram(string i, char s, char d);
        Datagram(const Datagram& rhs);

        string getID();
        void setID(string i);

        char getSrc();
        void setSrc(char s);

        char getDest();
        void setDest(char d);
};

#endif