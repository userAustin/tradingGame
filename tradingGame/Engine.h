#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

//Sam Daly
// 6 FEB 2023
//Trading Game Engine class


//Pre Declarations
class Engine;

/*
This file contains the Engine class. The purpose of this class is to tie together the
various elements of the game and provide the larger context in which they operate. It
is the canvas on which the game is painted.

The main part of the Engine is the game state. Game states are exactly what they sound like,
the different states the game can be in. These states include the splash screen, the menu screen,
the world map screen, and the port screen.

*/

#pragma region GameState

class GameState {
protected:
	Engine* engine = nullptr;

public:
	//Common Functions
	void SetEngine(Engine &targ);

	//Virtual Functions
	virtual void Update(float dt) = 0;

};

//World Map State
class GameState_World : public GameState {
private:
	//Data

public:
	//Constructor and Destructor
	GameState_World(Engine &engine);
	~GameState_World();

	//Primary Functions
	void Update(float dt);

};


#pragma endregion



class Engine
{
private:
	//Data
	GameState* currState = nullptr;
	GameState* prevState = nullptr;

	//Util
	void Init();

public:
	//Constructor and Destructor
	Engine();
	~Engine();

	//Primary Functions
	void Update();
	void SetState(GameState &newState);

};

