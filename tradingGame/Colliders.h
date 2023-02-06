#pragma once
#include <SFML/Graphics.hpp>

class BoxCollider
{
private:
	//Data
	sf::IntRect bounds;
	sf::Vector2f pos;

	bool isSleep = false;

	int objType = 0; //So the resolution phase can tell what two kinds of objects are colliding

public:
	//Constructors and Destructors


	//Primary Functions
	void setObjType(int type);
	int getObjType();

	void setPos(sf::Vector2f newPos);
	sf::Vector2f getPos();

	sf::IntRect getBounds();
	void setBounds(sf::IntRect newBounds);

	void update(float deltaTime);
	bool isCollidingWith(BoxCollider targ);

	void drawCollider(sf::RenderTarget* targWindow, sf::Color color = sf::Color::Green);

	void setSleep(bool value);
	bool getSleep();

};

