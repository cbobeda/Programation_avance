#include <iostream>
#include <SFML/Graphics.hpp>
#include "button.h"
#include "Shapes.h"

using namespace sf;

RenderWindow window(VideoMode(1920,1080),"SMFL");
shapes shapeCreator;
Color colorTab [8] = {Color::Black,Color::Blue,Color::Cyan,Color::Green,Color::Magenta,Color::Red,Color::White,Color::Yellow};
int currentColor = 0;
int Drawsize = 15;
Vector2i pos1;
Vector2i pos2;
bool drawing = false;
bool isSquaring = false;
button changeColor0(0,0,50,50);
button changeColor1(100,0,50,50);
button changeColor2(200,0,50,50);
button changeColor3(300,0,50,50);
button changeColor4(400,0,50,50);
button changeColor5(500,0,50,50);
button changeColor6(600,0,50,50);
button changeColor7(700,0,50,50);
button square(800,0,50,50);
Texture createimage(int x, int y)
{
    Image image;
    image.create(x,y,Color::White);
    Texture texture;
    texture.loadFromImage(image);
    return texture;
}

Image size(int dx,int dy,int size,Color couleur,Texture texture)
{
    Image imageBuffer = texture.copyToImage();
    for (int x = dx - size; x < dx + size; x++)
    {
        for (int y = dy - size; y < dy + size; y++)
        {
            if (y > 0 && x > 0)
            {
                imageBuffer.setPixel(x,y,couleur);
            }
        }
    }
    
    return imageBuffer;
    
}


Image changeColor(Texture texture)
{

    if (changeColor0.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
    {
        currentColor = 0;
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
    else if (square.check(Mouse::getPosition(window).x, Mouse::getPosition(window).y) || isSquaring)
    {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        isSquaring  = true;
        while (isSquaring)
        {
            if (Mouse::isButtonPressed(Mouse::Left) && Keyboard::isKeyPressed(Keyboard::A))
            {
                pos1 = Mouse::getPosition(window);
            }
            else if (Mouse::isButtonPressed(Mouse::Left) && Keyboard::isKeyPressed(Keyboard::E))
            {
                pos2 = Mouse::getPosition(window);
                isSquaring = false;
            }
        }
         texture.update(shapeCreator.square(pos1,pos2,Drawsize,colorTab[currentColor],texture));
    }
    return texture.copyToImage();
}

void main()
{
    Texture texture = createimage(window.getSize().x,window.getSize().y);
    window.setFramerateLimit(60);
    Vector2i prevMousePos;
    // Boucle principale
    while (window.isOpen())
    {
        Image imageBuffer = texture.copyToImage();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                drawing = true;
                prevMousePos = Mouse::getPosition(window);
            }
            else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                drawing = false;
            }
        }
        if (drawing && !isSquaring) {
            Vector2i currentMousePos = Mouse::getPosition(window);
            if (currentMousePos != prevMousePos) {
                shapeCreator.line(imageBuffer, prevMousePos, currentMousePos,Drawsize, colorTab[currentColor],texture);
                prevMousePos = currentMousePos;

                texture.update(imageBuffer);
            }
        }
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
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            Image buffer;
            buffer = texture.copyToImage();
            buffer.saveToFile("image.bmp");
        }
        texture.setSmooth(true);
        // Effacer la fenêtre
        window.clear();
        texture.update( changeColor(texture));
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
        window.draw(square.display(Color::Black));
        // Afficher le contenu
        window.display();
    }
}


