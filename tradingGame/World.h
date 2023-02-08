#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

//Sam Daly
//6 FEB 2023
//Trading Game World Class

/*
This file contains the world class. The purpose of the world class is to provide
and environment in which the player can operate. 

In this case the world consists of a 2D vector of tiles.
*/

class Tile {
private:
	//Data
	sf::Sprite sprite;
	sf::Texture* texture = nullptr;
	sf::Vector2f pos = {0,0};

	//Utility

public:
	//Constructor and Destructor
	Tile();
	~Tile();

	//Primary functions
	void Draw(sf::RenderWindow &window);
	void SetTexture(sf::Texture* newTexture);
	void SetPos(sf::Vector2f newPos);

	sf::Texture* GetTexture();

};

class World
{
private:
	//Data
	std::map<int, sf::Texture*> textureAtlas;
	int height;
	int width;
	int tileSize; //Assumed Square
	std::vector<std::vector<Tile*>*> tileVector;


	//Util
	void Init();

public:
	//Constructor and Destructor
	World();
	~World();
	//Primary Functions
	void SetTextureAtlas(std::map<int, sf::Texture*> newtextureAtlas);
	void FReadtextureAtlas(std::string filename); //Low Priority
	void WriteToFile(std::string filename);
	void ReadFromFile(std::string filename);
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

