#pragma once
#include "VisibleGameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Add(VisibleGameObject* gameObject);
	void Insert(VisibleGameObject* obj, float xPos, float yPos);

	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow* renderWindow);

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;

	/* Functor to use during foreach deallocation */
	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> & p) const
		{
			delete p.second;
		}
	};

};
