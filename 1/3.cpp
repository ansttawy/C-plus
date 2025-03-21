#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Moving Circle", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape circle(100); 
    circle.setFillColor(sf::Color::Green);
    circle.setOrigin(circle.getRadius(), circle.getRadius()); 

    float radius = 250.0f;
    float a = 0.0f;
    float aSpeed = 3.0f; 

    sf::Vector2f center(400.0f, 400.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        a+= aSpeed;
        if (a >= 360.0f) a -= 360.0f;

        circle.setRotation(a);

        float radians = a * 3.14159265f / 180.0f;
        float x = center.x + radius * std::cos(radians);
        float y = center.y + radius * std::sin(radians);
        circle.setPosition(x, y);

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

}