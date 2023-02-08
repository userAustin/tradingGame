#include "World.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Tile::SetTexture(sf::Texture* newTexture)
{
	if (newTexture == nullptr) {
		std::cout << "Cannot change tile texture to nullptr"  << std::endl;
		return;
	}

	texture = newTexture;
	sprite.setTexture(*texture);
}

void Tile::SetPos(sf::Vector2f newPos)
{
	pos = newPos;
	sprite.setPosition(pos);
}

void World::Init()
{

}

World::World()
{
	this->Init();
}

World::~World()
{
	for (int i = height - 1; i >= 0; i--) {
		for (int j = width - 1; j >= 0; j--) {
			delete tileVector.at(i)->at(j);
			//tileVector.at(i)->pop_back();
		}
		delete tileVector.at(i);
		//tileVector.at(i)->pop_back();
	}
}

void World::SetTextureAtlas(std::vector<sf::Texture*> newtextureAtlas)
{
	textureAtlas = newtextureAtlas;
}

void World::ReadFromFile(std::string filename)
{
	/*
	This function takes a filename (text file) and builds the 2D tile vector from that file.

	File Format
	----------
	height width
	tilesize
	0 1 2 3 4
	0 0 0 0 0
	...

	*/

	std::ifstream inFile;
	inFile.open(filename);

	//Check if file opened
	if (!inFile) {
		std::cout << "Could not open world file: " << filename << std::endl;
		return;
	}


	//Read the file
	int currRead;
	int i = 0;
	//Get Width, Height, and Tile Size
	inFile >> height >> width >> tileSize;

	//Make Empty Vector

	//Get Tiles
	for (int i = 0; i < height; i++) {
	
		//Allocate new row of tiles
		tileVector.push_back(new std::vector<Tile*>);

		for (int j = 0; j < width; j++) {
			//Allocate new Tile
			inFile >> currRead;
			Tile* newTile = new Tile();
			newTile->SetTexture(textureAtlas.at(currRead));
			newTile->SetPos({ j * (float)tileSize, i * (float)tileSize });

			tileVector.at(i)->push_back(newTile);

		}
	}

	//Close the file
	inFile.close();

}

void World::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			tileVector.at(i)->at(j)->Draw(window);
		}
	}
}
