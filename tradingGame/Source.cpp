#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ship.h"
/*
############	Possible Memory Leaks	###########

>	Ship.cpp, many functions allocate new Ship States, and if they are not properly destroyed
			  in the Ship class' SetState() function there may be a leak

>



*/

int main() {
	//Vars
	sf::RenderWindow window(sf::VideoMode(600,600), "Trading Game");
	sf::Event event;
	sf::Clock frameClock;
	float deltaTime = 0;

	sf::Texture circleTexture;
	circleTexture.loadFromFile("Textures/testCircle.png");

	Ship testShip;
	testShip.SetTexture(&circleTexture);

	// ###### WINDOW LOOP #########
	while (window.isOpen()) {

		//Update deltaTime
		deltaTime = frameClock.getElapsedTime().asSeconds();
		frameClock.restart();

		//## Event Loop ##
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}


		//## Update ##
		testShip.Update(deltaTime);


		//## Render ##
		window.clear();

			//Draw
		testShip.Draw(window);

		window.display();

	}

	return 0;
}