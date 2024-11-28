#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class shapes
{
public:
    Image line(Image& image, Vector2i start, Vector2i end,int size, Color color,Texture texture);
    Image square(Vector2i start, Vector2i end ,int size,Color couleur,Texture texture);
};
