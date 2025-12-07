#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "node.h"
#include "edge.h"

using namespace std;

class Display 
{
private:
    sf::RenderWindow window;
    sf::Font font;

public:
    Display(unsigned int width, unsigned int height);
    void draw(const vector<Node>& nodes, const vector<Edge>& edges);
    bool isOpen() const;
    void pollEvents();
};

#endif
