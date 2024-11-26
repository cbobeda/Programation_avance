#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class shapes
{
public:
    Image line(int dx1, int dy1, int dx2, int dy2,int size,Color couleur, Texture texture);
    Image square(int x1, int y1, int x2, int y2,int size,Color couleur,Texture texture);
};
