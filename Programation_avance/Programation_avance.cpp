#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

RenderWindow window(VideoMode(800,600),"SMFL");
Texture createimage(int x, int y)
{
    Image image;
    image.create(x,y,Color::White);
    Texture texture;
    texture.loadFromImage(image);
    return texture;
}

Image dessine(int x, int y,Texture texture)
{
    Image imageBuffer = texture.copyToImage();
    if (Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).y > 0)
    {
        for (int x = Mouse::getPosition(window).x - 10; x < Mouse::getPosition(window).x + 10; x++)
        {
            for (int y = Mouse::getPosition(window).y - 10; y < Mouse::getPosition(window).y + 10; y++)
            {
                if (y > 0 && x > 0)
                {
                    imageBuffer.setPixel(x,y,Color::Black);
                }
            }
        }
    }
    return imageBuffer;
    
}

void main()
{
    
    CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(Color::Green);
    Texture texture = createimage(window.getSize().x,window.getSize().y);
    // Boucle principale
    while (window.isOpen())
    {
        Image imageBuffer = texture.copyToImage();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); // Fermer la fenêtre
        }
        std::cout <<  Mouse::getPosition(window).x << ':' << Mouse::getPosition(window).y<< std::endl;
        texture.update(dessine(Mouse::getPosition(window).x,Mouse::getPosition(window).y,texture));
        texture.setSmooth(true);
        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        Sprite sprite(texture);
        window.draw(sprite);
        // Afficher le contenu
        window.display();
    }
}


