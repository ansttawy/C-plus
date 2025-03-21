#include <SFML/Graphics.hpp>
#include <iostream> 

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consola.ttf")) 
    {
        std::cout << "Error. Can't load font!" << std::endl;
        std::exit(1);
    }    


    sf::Text text;
    text.setFont(font); 
    text.setString(L"Привет Мир!"); 
    text.setCharacterSize(50); 
    text.setFillColor(sf::Color(70, 160, 100)); 
    text.setPosition(300, 200); 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }

    return 0;
}