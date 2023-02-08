#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "World.h"

/*
############	Possible Memory Leaks	###########

>	Ship.cpp, many functions allocate new Ship States, and if they are not properly destroyed
			  in the Ship class' SetState() function there may be a leak.

>	World.cpp, When reading world from file a vector of vectors of pointers is allocated. If
	not properly destroyed in ~World() a memory leak may result.



*/

int main() {
	//Vars
	sf::RenderWindow window(sf::VideoMode(600,600), "Trading Game");
	sf::Event event;
	sf::Clock frameClock;
	float deltaTime = 0;

	//Texture Atlas Setup
	sf::Texture red, green, blue;

	red.loadFromFile("Textures/red32.png");
	green.loadFromFile("Textures/green32.png");
	blue.loadFromFile("Textures/blue32.png");

	std::vector<sf::Texture*> testAtlas;
	testAtlas.push_back(&red);
	testAtlas.push_back(&green);
	testAtlas.push_back(&blue);

	//World Setup
	World testWorld;
	testWorld.SetTextureAtlas(testAtlas);
	testWorld.ReadFromFile("world_tst.txt");


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
		


		//## Render ##
		window.clear();

			//Draw
		testWorld.Draw(window);

		window.display();

	}

	return 0;
}