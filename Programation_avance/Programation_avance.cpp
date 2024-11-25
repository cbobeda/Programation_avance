#include <SFML/Graphics.hpp>

using namespace sf;
void main()
{
    RenderWindow window(VideoMode(800,600),"SMFL");
    CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(Color::Green);

    // Boucle principale
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); // Fermer la fenêtre
        }

        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        window.draw(shape);
        // Afficher le contenu
        window.display();
    }
}