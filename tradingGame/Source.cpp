#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
	//Vars
	sf::RenderWindow window(sf::VideoMode(600,600), "Trading Game");
	sf::Event event;
	int timer = 0;

	// ###### WINDOW LOOP #########
	while (window.isOpen()) {

		//## Event Loop ##
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}


		//## Update ##
		timer++;
		if (timer == 10000) {
			std::cout << "Got'eem" << std::endl;
			timer = 0;
		}


		//## Render ##
		window.clear();

			//Draw

		window.display();

	}

	return 0;
}