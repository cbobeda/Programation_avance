#include <iostream>
#include <SFML/Graphics.hpp>
#include "button.h"

using namespace sf;

RenderWindow window(VideoMode(1920,1080),"SMFL");
Color colorTab [8] = {Color::Black,Color::Blue,Color::Cyan,Color::Green,Color::Magenta,Color::Red,Color::White,Color::Yellow};
int currentColor = 0;
int Drawsize = 10;
button changeColor0(0,0,50,50);
button changeColor1(100,0,50,50);
button changeColor2(200,0,50,50);
button changeColor3(300,0,50,50);
button changeColor4(400,0,50,50);
button changeColor5(500,0,50,50);
button changeColor6(600,0,50,50);
button changeColor7(700,0,50,50);
Texture createimage(int x, int y)
{
    Image image;
    image.create(x,y,Color::White);
    Texture texture;
    texture.loadFromImage(image);
    return texture;
}

Image dessine(int x, int y,int size,Color couleur,Texture texture)
{
    Image imageBuffer = texture.copyToImage();
    if (Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).y > 0)
    {
        for (int x = Mouse::getPosition(window).x - size; x < Mouse::getPosition(window).x + size; x++)
        {
            for (int y = Mouse::getPosition(window).y - size; y < Mouse::getPosition(window).y + size; y++)
            {
                if (y > 0 && x > 0)
                {
                    imageBuffer.setPixel(x,y,couleur);
                }
            }
        }
    }
    return imageBuffer;
    
}
Texture changeColor(Texture texture)
{
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        if (changeColor0.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 0;
                
            std::cout << currentColor << std::endl;
        }
        else if (changeColor1.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 1;
        }
        else if (changeColor2.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 2;
        }
        else if (changeColor3.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 3;
        }
        else if (changeColor4.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 4;
        }
        else if (changeColor5.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 5;
        }
        else if (changeColor6.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 6;
        }
        else if (changeColor7.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            currentColor = 7;
        }
        else
        {
            texture.update(dessine(Mouse::getPosition(window).x,Mouse::getPosition(window).y,Drawsize,colorTab[currentColor],texture));
        }
    }
    return texture;
}
void main()
{
    window.setFramerateLimit(60);
    
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
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            Drawsize--;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            Drawsize++;
        }
        if (Mouse::isButtonPressed(Mouse::Right))
        {
            texture.update(createimage(window.getSize().x,window.getSize().y));
        }
        texture = changeColor(texture);
        texture.setSmooth(true);
        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        Sprite sprite(texture);
        window.draw(sprite);
        window.draw(changeColor0.display(Color::Black));
        window.draw(changeColor1.display(Color::Blue));
        window.draw(changeColor2.display(Color::Cyan));
        window.draw(changeColor3.display(Color::Green));
        window.draw(changeColor4.display(Color::Magenta));
        window.draw(changeColor5.display(Color::Red));
        window.draw(changeColor6.display(Color::White));
        window.draw(changeColor7.display(Color::Yellow));
        // Afficher le contenu
        window.display();
    }
}


