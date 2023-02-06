#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
	//Vars
	sf::RenderWindow window(sf::VideoMode(600,600), "Trading Game");
	sf::Event event;


	// ###### WINDOW LOOP #########
	while (window.isOpen()) {

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

		window.display();

	}

	return 0;
}