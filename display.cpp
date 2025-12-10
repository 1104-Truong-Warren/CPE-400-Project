#include "display.h"
#include <iostream>

// This creates the SFML window with given dimensions and title of the window
Display::Display(unsigned int width, unsigned int height) : window(sf::VideoMode(width, height), "Network of routers in the Network Layer")
{
    // Sets the font to Arial
    if (!font.openFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) 
    {
        cerr << "Failed to load font!" << endl;
    }
}

// This function draws the network graph, takes in nodes and edges
void Display::draw(const vector<Node>& nodes, const vector<Edge>& edges)
{
    window.clear(sf::Color::Black); // Background color

    // Draws edges
    for (const auto& e : edges) 
    {
        window.draw(e.getLine());
    }

    // Draws nodes and labels
    for (const auto& n : nodes) 
    {
        window.draw(n.getShape()); // Draws the node's shape such as a circle

        sf::Text text(font, string(1, n.getLabel()), 20);
        text.setFillColor(sf::Color::White);

        sf::Vector2f pos = n.getPosition();
        text.setPosition(pos.x - 6.f, pos.y - 12.f); // Center text
        window.draw(text);
    }

    window.display();
}

// This function checks if the display is currently opened
bool Display::isOpen() const 
{
    return window.isOpen();
}

// This function handles the mouse clicks, keyboard input, and window resizing in the window
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
