#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>

int main()
{
    //start a window called window
    sf::RenderWindow window (sf::VideoMode (850,800), "Auto Sorter");

    //load texture of "done sign"
    sf::Texture playertexture; 
    playertexture.loadFromFile("Pics/done.png");
    sf::Sprite player;
    player.setTexture(playertexture);
    player.setPosition(300,100);
    player.setScale(0.5f,0.5f);


    // Create a random number generator
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd()); // Seed the generator with the random device
    std::uniform_int_distribution<> distr(1, 600); // Define the range [1, 100]


    //make a vector to store the rects
    std::vector <sf::RectangleShape> rec;

    //make a variable to store heights
    std::vector <int> heets;

    //for loop
    
    for (int i = 0; i < 600; i = i + 5)
    {
        std::string rectname = std::to_string(i);
        int rectheight =  distr(gen);
        heets.push_back(rectheight);
        sf::RectangleShape rect(sf::Vector2f(5, rectheight));
        rect.setPosition(i*1.2 , 800-rectheight);
        rect.setFillColor(sf::Color::Green);
        rec.push_back(rect);
    }
    
    //set frame rate
    window.setFramerateLimit(60);
    int i = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //game loop (gets repeated each frame)
    while (window.isOpen())
    {
    
        //create an event to handle one time events
        sf::Event event;

        //Here, pollEvent is feeding the variable event all the events that are happening
        while (window.pollEvent(event) )
        {
            //close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //make a black window
        window.clear(sf::Color::Black);


        if(i < rec.size())  
        {
            int curent = heets[i];
            sf::RectangleShape crunt = rec[i];
            int j = i - 1;
            while (j >= 0 && heets[j] > curent )
            {
                heets[j + 1] = heets[j];
                rec[j + 1] = rec[j];
                j-- ;
            }
            heets[j+1] = curent;
            rec[j+1] = crunt;

            for (int k = 0; k < rec.size(); k++)
            {
                rec[k].setPosition(k * 7.0f, 800 - heets[k]); // Adjust position based on heights
            }

            //draw all rectangles in the rec variable
            for (const auto& rect : rec)
            {
                window.draw(rect);
            }
            
            window.display();
            i = i + 1;
            sf::sleep(sf::milliseconds(50));
        }
        else
        {
            for (const auto& rect : rec)
            {
                window.draw(rect);
            }
            window.draw(player);
            window.display();
        }
    }
}
