#include <SFML/Graphics.hpp>
float speed = 0.11;
float dir = 1.f;
float d = 20.f;
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(d);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shape.move(speed * dir, 0);
        window.clear();
        window.draw(shape);
        window.display();
        if (shape.getPosition().x > 200 - 2*shape.getRadius()|| shape.getPosition().x < 0)
        {
            dir *= -1;
            shape.scale(1.1, 1.1);
        }
    }

    return 0;
}