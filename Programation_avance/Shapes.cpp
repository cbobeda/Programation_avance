#include "Shapes.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

Image shapes::line(Image& image, Vector2i start, Vector2i end,int size, Color color,Texture texture)
{
    Image imageBuffer = texture.copyToImage();
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = (start.x < end.x) ? 1 : -1;
    int sy = (start.y < end.y) ? 1 : -1;
    int err = dx - dy;
    while (true) {
        for (int x = start.x - size; x < start.x + size; x++)
        {
            for (int y = start.y - size; y < start.y + size; y++)
            {
                if (y > 0 && x > 0)
                {
                    image.setPixel(x,y,color);
                }
            }
        }
        if (start.x == end.x && start.y == end.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            start.y += sy;
        }
    }
    
    return imageBuffer;
}

Image shapes::square(Vector2i start, Vector2i end ,int size,Color couleur,Texture texture)
{
    Image imageBuffer = texture.copyToImage();
    texture.update(line(imageBuffer,Vector2i (start.x, start.y), Vector2i(end.x, start.y),size, couleur, texture));
    texture.update(line(imageBuffer,Vector2i(start.x, start.y), Vector2i(start.x, end.y),size, couleur, texture));
    texture.update(line(imageBuffer,Vector2i(end.x, end.y), Vector2i(end.x, start.y),size, couleur, texture));
    texture.update(line(imageBuffer,Vector2i(end.x, end.y), Vector2i(start.x, end.y),size, couleur, texture));

    imageBuffer = texture.copyToImage();
    return imageBuffer;
}