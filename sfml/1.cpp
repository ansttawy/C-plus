#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving rectangle", sf::Style::Default);
    window.setFramerateLimit(60);
    
    sf::RectangleShape rectangle(sf::Vector2f(100, 100));;
    rectangle.setPosition(sf::Vector2f{400, 400});
    rectangle.setFillColor(sf::Color::Yellow); 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        rectangle.rotate(0.5f);

        window.clear(sf::Color::Black);
        window.draw(rectangle);

        window.display();
    }
}



