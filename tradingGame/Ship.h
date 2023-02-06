#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Colliders.h"

/* ######## DESCRIPTION ###########

This file contains the neccesary data and functions to display and manipulate the games ships.

	


*/

//Pre Declarations
class Ship;

#pragma region Ship States

class ShipState {
protected:
	//Common Data
	int stateType = -1;
	Ship* parentShip;
	sf::Vector2f pos = {0,0};
	sf::Keyboard::Key UpKey = sf::Keyboard::W;
	sf::Keyboard::Key DownKey = sf::Keyboard::S;
	sf::Keyboard::Key LeftKey = sf::Keyboard::A;
	sf::Keyboard::Key RightKey = sf::Keyboard::D;

public:
	//Common Functions
	void SetParentShip(Ship* targ);

	int GetStateType();

	//Virtual Functinos
	virtual void Update(float dt) = 0;
};

// ###	IDLE	###
class ShipState_Idle : public ShipState {
private:
	//Data
	

public:
	//Constructor and Destructor
	ShipState_Idle();
	~ShipState_Idle();

	//Primary Functions
	void Update(float dt);


};

//###	MOVING	###
class ShipState_Moving : public ShipState {
private:
	//Data


public:
	//Constructor and Destructor
	ShipState_Moving();
	~ShipState_Moving();

	//Primary Functions
	void Update(float dt);


};

#pragma endregion



class Ship
{
protected:
	//Data
	ShipState* currState;
	ShipState* prevState;

	sf::Vector2f pos;
	float speed;

	sf::Sprite sprite;
	sf::Texture* texture;
	sf::IntRect textureRect;
	//BoxCollider collider;

	//Util Functions
	void Init(); //Sets up inital state of ship
	

public:
	//Constructor and Destructor
	Ship();
	~Ship();

	//Primary Functions
	void Update(float dt);
	void Draw(sf::RenderWindow &window);
	void SetPos(sf::Vector2f newPos);
	void SetState(ShipState* newState);
	void SetTexture(sf::Texture* newTexture);
	void SetTextureRect(sf::IntRect newRect);

	float GetSpeed();
	sf::Vector2f GetPos();

};

