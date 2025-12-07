#include "display.h"
#include <iostream>

Display::Display(unsigned int width, unsigned int height) : window(sf::VideoMode(width, height), "Network of routers in the Network Layer")
{
    if (!font.openFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) 
    {
        cerr << "Failed to load font!" << endl;
    }
}

void Display::draw(const vector<Node>& nodes, const vector<Edge>& edges)
{
    window.clear(sf::Color::Black); // Background color

    // Draw edges
    for (const auto& e : edges) 
    {
        window.draw(e.getLine());
    }

    // Draw nodes and labels
    for (const auto& n : nodes) 
    {
        window.draw(n.getShape());

        sf::Text text(font, string(1, n.getLabel()), 20);
        text.setFillColor(sf::Color::White);

        sf::Vector2f pos = n.getPosition();
        text.setPosition(pos.x - 6.f, pos.y - 12.f); // Center text
        window.draw(text);
    }

    window.display();
}

bool Display::isOpen() const 
{
    return window.isOpen();
}

void Display::pollEvents() 
{
    while (const optional event = window.pollEvent()) 
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}
