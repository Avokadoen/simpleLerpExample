#include <SFML/Graphics.hpp>
#include "lerper.hpp"
#include "GLOBALS.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "lerp test");
	Lerper lerper(sf::Color::Blue, sf::Vector2f(0,0), sf::Vector2f(50,50));

	sf::Clock clock;
	clock.restart();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		float dt = clock.restart().asSeconds();
		lerper.update(dt);

        window.clear();
		lerper.draw(window);
        window.display();
    }

    return 0;
}
