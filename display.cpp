#include "display.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Display::Display(unsigned int width, unsigned int height)
    : window(sf::VideoMode({width, height}), "Network Edges")
{
    if (!font.openFromFile("/System/Library/Fonts/Supplemental/Arial.ttf"))
        std::cerr << "Failed to load font!" << std::endl;
}

// Edges-only: cannot draw lines without source coordinates
void Display::draw(const std::vector<Edge*>& edges)
{
    window.clear(sf::Color::Black);
    window.display();
}

bool Display::isOpen() const
{
    return window.isOpen();
}

void Display::pollEvents()
{
    while (auto eventOpt = window.pollEvent())
    {
        const sf::Event& event = *eventOpt;
        if (event.is<sf::Event::Closed>())
            window.close();
    }
}
