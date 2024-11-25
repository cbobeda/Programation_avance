#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void main()
{
    IpAddress ip = IpAddress("127.0.0.1");
    sf::TcpSocket socket;
    char connectionType, mode;
    string text = "connection established :";
    Text displayText;
    displayText.setPosition(0,0);
    displayText.setCharacterSize(24);
    displayText.setFillColor(sf::Color::Red);
    displayText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    char buffer[2000];
    SIZE_T recieved;
    cout << "Enter connection type: " << endl;
    cin >> connectionType;
    RenderWindow window(VideoMode(800,600),"SMFL");
    

    if (connectionType == 's')
    {
        TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
        text += "Connected to server";
        
    }
    else if (connectionType == 'c')
    {
        socket.connect(ip,2000);
        text += "Client connected";
        
    }
    socket.send(text.c_str(),text.length()+1);
    socket.receive(buffer,sizeof(buffer),recieved);
    cout << buffer << endl;

    
    
    // Boucle principale
    while (window.isOpen())
    {
        displayText.setString(text);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close(); // Fermer la fenêtre
            }
        }

        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        window.draw(displayText);
        // Afficher le contenu
        window.display();
    }
}