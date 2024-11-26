#include "Shapes.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

Image shapes::line(int dx1, int dy1, int dx2, int dy2,int size, Color couleur, Texture texture)
{
    Image imageBuffer = texture.copyToImage();
    
    // Calculer la différence entre les deux points
    int dx = abs(dx2 - dx1);
    int dy = abs(dy2 - dy1);
    int sx = (dx1 < dx2) ? 1 : -1;
    int sy = (dy1 < dy2) ? 1 : -1;
    int err = dx - dy;

    while (true) 
    {
        // Vérifier si les coordonnées sont dans les limites de l'image
        if (dx1 >= 0 && dx1 < imageBuffer.getSize().x && dy1 >= 0 && dy1 < imageBuffer.getSize().y)
        {
            for (int x = dx1 - size; x < dx1 + size; x++)
            {
                for (int y = dy1 - size; y < dy1 + size; y++)
                {
                    if (y > 0 && x > 0)
                    {
                        imageBuffer.setPixel(x,y,couleur);
                    }
                }
            }
            // Dessiner le pixel à la position actuelle
            //imageBuffer.setPixel(dx1, dy1, couleur);
        }

        // Si on atteint le point final, sortir de la boucle
        if (dx1 == dx2 && dy1 == dy2) break;

        // Calculer l'erreur et ajuster les coordonnées
        int e2 = err * 2;
        if (e2 > -dy) 
        {
            err -= dy;
            dx1 += sx;
        }
        if (e2 < dx) 
        {
            err += dx;
            dy1 += sy;
        }
    }
    
    return imageBuffer;
}

Image shapes::square(int x1, int y1, int x2, int y2,int size,Color couleur,Texture texture)
{
    texture.update(line(x1, y1, x2, y1,size, couleur, texture));
    texture.update(line(x1, y1, x1, y2,size, couleur, texture));
    texture.update(line(x2, y2, x2, y1,size, couleur, texture));
    texture.update(line(x2, y2, x1, y2,size, couleur, texture));
    Image imageBuffer = texture.copyToImage();
    return imageBuffer;
}