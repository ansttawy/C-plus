#include <SFML/Graphics.hpp>
#include <iostream> 
#include <string> 

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Mouse", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consola.ttf")) 
    {
        std::cout << "Error. Can't load font!" << std::endl;
        std::exit(1);
    }    


    sf::Text text;
    text.setFont(font); 
    text.setCharacterSize(30); 
    text.setFillColor(sf::Color(70, 160, 100)); 
    text.setPosition(100, 100); 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i p = sf::Mouse::getPosition(window);
        sf::Vector2f q = window.mapPixelToCoords(p);

        std::string c = " (" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")," +
                                      "(" + std::to_string(q.x) + ", " + std::to_string(q.y) + ")";

        text.setString(c);

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
}