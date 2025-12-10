#include "display.h"
#include <iostream>
#include <map>
#include <cmath>

// This creates the SFML window with given dimensions and title of the window
Display::Display(unsigned int width, unsigned int height) : window(sf::VideoMode({width, height}), "Network of routers in the Network Layer")
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

    // Create a map to store node positions by ID
    static std::map<char, sf::Vector2f> nodePositions;
    
    // Initialize positions if empty (you'll need to set these properly in your main code)
    if (nodePositions.empty()) {
        // Assign positions in a circle or grid pattern
        float centerX = 400.f;
        float centerY = 300.f;
        float radius = 200.f;
        int nodeCount = nodes.size();
        
        for (size_t i = 0; i < nodes.size(); ++i) {
            float angle = 2 * 3.14159f * i / nodeCount;
            char nodeId = nodes[i].getId();
            nodePositions[nodeId] = sf::Vector2f(
                centerX + radius * std::cos(angle),
                centerY + radius * std::sin(angle)
            );
        }
    }

    // Draws edges - THIS WON'T WORK PROPERLY BECAUSE Edge CLASS DOESN'T STORE SOURCE NODE
    // You need to either modify Edge class or pass source node information differently
    for (const auto& e : edges) 
    {
        // Since Edge only has destination, we can't draw lines properly
        // This is just placeholder code
        sf::VertexArray line(sf::PrimitiveType::Lines, 2);
        line[0].position = sf::Vector2f(100.f, 100.f);
        line[1].position = sf::Vector2f(200.f, 200.f);
        line[0].color = sf::Color::White;
        line[1].color = sf::Color::White;
        window.draw(line);
    }

    // Draws nodes and labels
    for (const auto& n : nodes) 
    {
        char nodeId = n.getId();
        sf::Vector2f pos = nodePositions[nodeId];
        
        // Create a circle shape for the node
        sf::CircleShape circle(20.f);
        circle.setFillColor(sf::Color::Blue);
        circle.setOutlineColor(sf::Color::White);
        circle.setOutlineThickness(2.f);
        circle.setPosition(sf::Vector2f(pos.x - 20.f, pos.y - 20.f));
        window.draw(circle); // Draws the node's shape such as a circle

        // Create text label using node ID
        sf::Text text(font, std::string(1, nodeId), 20);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(pos.x - 6.f, pos.y - 12.f)); // Center text
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
    std::optional<sf::Event> event = window.pollEvent();
    while (event) 
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        event = window.pollEvent();
    }
}