#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <SFML/Graphics.hpp>
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
namespace GameEngine
{
	class BlockCreationManager
	{
	public:
		~BlockCreationManager();
		void Update();
		static BlockCreationManager* GetInstance() { if (!sm_instance) sm_instance = new BlockCreationManager(); return sm_instance; }
		static Entity* CreateBlock(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
		static TextRenderComponent* CreateText(Entity* entity, std::string str, int size, sf::Color color);
	private:
		BlockCreationManager();
		static BlockCreationManager* sm_instance;	
	};
}

