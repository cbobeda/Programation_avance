#include "button.h"

bool button::check(int x, int y)
{
    
    if (x > posX && x < posX + width && y > posY && y < posY + height)
        return true;
    else
        return false;
}

sf::RectangleShape button::display(sf::Color couleur)
{
    sf::RectangleShape rectangle(sf::Vector2f(height, width));
    rectangle.setPosition(posX, posY);
    rectangle.setFillColor(couleur);
    return rectangle;
}

