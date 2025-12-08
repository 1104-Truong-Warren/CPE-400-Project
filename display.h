#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "edge.h"

class Display 
{
private:
    sf::RenderWindow window;
    sf::Font font;

public:
    Display(unsigned int width, unsigned int height);
    void draw(const std::vector<Edge*>& edges);  // <-- must match cpp
    bool isOpen() const;
    void pollEvents();
};

#endif
