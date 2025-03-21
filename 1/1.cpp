#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving Circle", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape circle(100);
    circle.setPosition(sf::Vector2f{0, 400});
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

        circle.move(speed, 0);

        if (circle.getPosition().x > 800)
        {
            circle.setPosition(-200, 400);
        }
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

}



//g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system