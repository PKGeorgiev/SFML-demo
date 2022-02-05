#pragma once
#include <SFML/Graphics.hpp>
#include <string>

struct SceneDescriptor
{
	std::string name;
	void (*initialize)(sf::RenderWindow&);
	void (*destroy)(sf::RenderWindow&);
	void (*draw)(sf::RenderWindow&);
	bool (*handleEvents)(sf::RenderWindow&, sf::Event&, std::string&);
};