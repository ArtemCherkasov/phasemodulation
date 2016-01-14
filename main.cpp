#include <SFML/Graphics.hpp>

#include "Headers/LowFrequencySignal.h"
#include "Headers/HiFrequencySignal.h"

#define WIDTH 1024
#define HEIGHT 768

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    sf::View view(sf::FloatRect(0, 0, WIDTH, HEIGHT));
    sf::CircleShape shape(150.f);
    sf::Clock clock;
    shape.setFillColor(sf::Color::Green);

    LowFrequencySignal *f = new LowFrequencySignal(&window);
    HiFrequencySignal *m = new HiFrequencySignal(&window, f);

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time time = clock.restart();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

        }

        window.clear(sf::Color::White);
        f->drawDecartCoordinate();
        f->drawSignal();
        m->drawDecartCoordinate();
        m->drawSignal();
        window.setView(view);
        window.display();


    }
    delete(f);
    delete(m);
    return 0;
}
