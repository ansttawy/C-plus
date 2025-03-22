#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving Circle", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape circle(30); 
    circle.setPosition(400, 400); 
    circle.setFillColor(sf::Color::Green);

    float speed = 1.5f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            circle.move(-speed, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            circle.move(speed, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            circle.move(0, -speed); 
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            circle.move(0, speed); 
        

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

}