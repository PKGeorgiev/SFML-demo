#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "SceneDescriptor.h"
#include "Scene1.h"
#include <algorithm>

void createScenes(std::vector<SceneDescriptor*>& scenes, sf::RenderWindow& win)
{
    scenes.push_back(createScene1());
}

void initScenes(std::vector<SceneDescriptor*>& scenes, sf::RenderWindow& win)
{
    for (auto scene : scenes)
    {
        scene->initialize(win);
    }
}

void destroyScenes(std::vector<SceneDescriptor*>& scenes, sf::RenderWindow& win)
{
    for (auto scene : scenes)
    {
        scene->destroy(win);
    }
}

SceneDescriptor* getSceneByName(std::vector<SceneDescriptor*>& scenes, SceneDescriptor* cs, std::string name)
{
    if (name == "")
    {
        return cs;
    }

    for (auto scene : scenes)
    {
        if (scene->name == name)
        {
            return scene;
        }
    }

    return cs;
}

int main()
{
    bool shoulRun = true;
    SceneDescriptor* currentScene = nullptr;
    std::vector<SceneDescriptor*> scenes;
    sf::RenderWindow window(sf::VideoMode(800, 900), "SFML works!");
    
    createScenes(scenes, window);
    initScenes(scenes, window);
    
    currentScene = scenes[0]; // Size check!!!
    
    // To replace createScenes / initScenes
    // std::for_each(scenes.begin(), scenes.end(), [&](SceneDescriptor* scene) 
    // { 
    //     scene->initialize(window); 
    // });

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                shoulRun = false;
                window.close();
                break;
            }

            std::string nextScene;

            shoulRun = currentScene->handleEvents(window, event, nextScene);

            if (!shoulRun)
            {
                window.close();
                break;
            } 

            currentScene = getSceneByName(scenes, currentScene, nextScene);
        }

        if (shoulRun)
        {
            window.clear();
            currentScene->draw(window);
            window.display();
        }
    }

    destroyScenes(scenes, window);

    return 0;
}