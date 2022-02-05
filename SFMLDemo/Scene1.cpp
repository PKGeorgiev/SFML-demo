#include "Scene1.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

struct scene1
{
	sf::CircleShape* shape;
	sf::Texture* background;
	sf::Sprite* backgroundSprite;
} scene1;

void initializeScene1(sf::RenderWindow& win)
{
	std::cout << "Initializing Scene1\n";

	scene1.background = new sf::Texture();
	scene1.background->loadFromFile("./images/Home-page.png");	

	scene1.backgroundSprite = new sf::Sprite(*scene1.background);
	
	scene1.shape = new sf::CircleShape(100.f);
	scene1.shape->setFillColor(sf::Color::Green);
}

void destroyScene1(sf::RenderWindow& win)
{
	std::cout << "Destroying Scene1\n";
	delete scene1.backgroundSprite;
	delete scene1.background;	
	delete scene1.shape;
}

bool handleScene1Events(sf::RenderWindow& win, sf::Event& evt, std::string& nextScene)
{
	// Main control logic
	switch (evt.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		std::cout << evt.mouseButton.x << ", " << evt.mouseButton.y << "\n";

		if (evt.mouseButton.x >= 234 && evt.mouseButton.x <= 557 &&
			evt.mouseButton.y >= 409 && evt.mouseButton.y <= 500)
		{
			// The timeline button was pressed
			nextScene = "Scene 2";
			scene1.shape->setFillColor(sf::Color::Red);
		}
		
		if (evt.mouseButton.x >= 233 && evt.mouseButton.x <= 557 &&
			evt.mouseButton.y >= 724 && evt.mouseButton.y <= 814)
		{
			// The exit button was pressed
			return false;
		}


	}; break;
	default:
		break;
	}

	return true;
}

void drawScene1(sf::RenderWindow& win)
{
	// Used to draw something
	win.draw(*scene1.backgroundSprite);
	win.draw(*scene1.shape);
}

SceneDescriptor* createScene1()
{
	SceneDescriptor* sd = new SceneDescriptor();

	sd->name = "Main menu";
	sd->initialize = &initializeScene1;
	sd->destroy = &destroyScene1;
	sd->initialize = &initializeScene1;
	sd->handleEvents = &handleScene1Events;
	sd->draw = &drawScene1;

	return sd;
}
