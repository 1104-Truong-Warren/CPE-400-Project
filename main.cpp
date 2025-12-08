#include <iostream>
#include "edge.h"
#include "datagram.h"
#include "node.h"
#include "display.h"
using namespace std;

int main(int argc, char* argv[]) {
    
    Node a;
    Node b;
    flagEnum flag=ROUTE_CHANGE;
    Datagram datagram("ab", &a, &b, 0, flag, false);
    cout<<datagram.getID()<<'\n'<<datagram.getSrc()<<'\n'<<datagram.getDest()<<'\n'<<flag<<'\n';

    //cout<<edge.getID()<<'\n';
    //cout << "This is MyProject" << endl;
    return 0;
}
