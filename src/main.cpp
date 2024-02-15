#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    window.setFramerateLimit(144);

    // Create a white square
    sf::RectangleShape square(sf::Vector2f(200, 200)); // Size of the square
    square.setFillColor(sf::Color::White);

    // Position the square in the middle of the screen
    sf::FloatRect squareBounds = square.getLocalBounds();
    square.setOrigin(squareBounds.left + squareBounds.width / 2.0f, squareBounds.top + squareBounds.height / 2.0f);
    square.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        // Draw the square
        window.draw(square);
        window.display();
    }

    return 0;
}
