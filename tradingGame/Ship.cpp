#include "Ship.h"


void ShipState::SetParentShip(Ship* targ)
{
	parentShip = targ;
	pos = parentShip->GetPos();
}

int ShipState::GetStateType()
{
	return stateType;
}


ShipState_Idle::ShipState_Idle()
{
	stateType = 0;
}

ShipState_Idle::~ShipState_Idle()
{
}

void ShipState_Idle::Update(float dt)
{
	//Null Parent Gaurd
	if (this->parentShip == nullptr) {
		std::cout << "Cannot update ship state, null parent" << std::endl;
		return;
	}
	//Get player input (CHECK HERE FOR MEMORY LEAK)(Consider Refactor, repetitive code)

	if (sf::Keyboard::isKeyPressed(UpKey)) {
		ShipState_Moving* newState = new ShipState_Moving();
		newState->SetParentShip(this->parentShip);
		this->parentShip->SetState(newState);
		std::cout << "Creating move state" << std::endl;

	}
	if (sf::Keyboard::isKeyPressed(LeftKey)) {
		ShipState_Moving* newState = new ShipState_Moving();
		newState->SetParentShip(this->parentShip);
		this->parentShip->SetState(newState);
		std::cout << "Creating move state" << std::endl;

	}
	if (sf::Keyboard::isKeyPressed(DownKey)) {
		ShipState_Moving* newState = new ShipState_Moving();
		newState->SetParentShip(this->parentShip);
		this->parentShip->SetState(newState);
		std::cout << "Creating move state" << std::endl;

	}
	if (sf::Keyboard::isKeyPressed(RightKey)) {
		ShipState_Moving* newState = new ShipState_Moving();
		newState->SetParentShip(this->parentShip);
		this->parentShip->SetState(newState);
		std::cout << "Creating move state" << std::endl;
	}

	//Do idle state stuff


	
}


ShipState_Moving::ShipState_Moving()
{
	stateType = 1;
}

ShipState_Moving::~ShipState_Moving()
{
}

void ShipState_Moving::Update(float dt)
{
	//Null Parent Gaurd
	if (this->parentShip == nullptr) {
		std::cout << "Cannot update ship state, null parent" << std::endl;
		return;
	}

	bool isIdle = true;

	//# Up
	if (sf::Keyboard::isKeyPressed(UpKey)) {
		pos.y -= parentShip->GetSpeed() * dt;
		isIdle = false;
	}
	//# Down
	if (sf::Keyboard::isKeyPressed(DownKey)) {
		pos.y += parentShip->GetSpeed() * dt;
		isIdle = false;
	}
	//# Left
	if (sf::Keyboard::isKeyPressed(LeftKey)) {
		pos.x -= parentShip->GetSpeed() * dt;
		isIdle = false;
	}
	//# Right
	if (sf::Keyboard::isKeyPressed(RightKey)) {
		pos.x += parentShip->GetSpeed() * dt;
		isIdle = false;
	}

	parentShip->SetPos(pos);

	if (isIdle) {
		//If no input key is pressed (ALSO LOOK HERE FOR MEMORY LEAKS)
		ShipState_Idle* newIdleState = new ShipState_Idle();
		newIdleState->SetParentShip(this->parentShip);
		parentShip->SetState(newIdleState);
		std::cout << "Creating Idle State" << std::endl;

	}


}

void Ship::Init()
{
	pos = { 0,0 };
	currState = new ShipState_Idle();
	currState->SetParentShip(this);
	prevState = new ShipState_Idle();
	prevState->SetParentShip(this);
	textureRect = { 0,0,32,32};
	speed = 100;
}

Ship::Ship()
{
	this->Init();
}

Ship::~Ship()
{
}

void Ship::Update(float dt)
{
	currState->Update(dt);
	sprite.setPosition(pos);
}

void Ship::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Ship::SetPos(sf::Vector2f newPos)
{
	pos = newPos;
}

void Ship::SetState(ShipState* newState)
{
	delete prevState;
	prevState = currState;
	currState = newState;
}

void Ship::SetTexture(sf::Texture* newTexture)
{
	texture = newTexture;
	sprite.setTexture(*texture);
	sprite.setTextureRect(textureRect);
}

void Ship::SetTextureRect(sf::IntRect newRect)
{
	textureRect = newRect;
	sprite.setTextureRect(textureRect);
}

float Ship::GetSpeed()
{
	return speed;
}

sf::Vector2f Ship::GetPos()
{
	return pos;
}
