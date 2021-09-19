#include "CreateBrickComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/BlockCreationManager.h"
#include "GameEngine/EntitySystem/Components/CollidablePushComponent.h"
#include <SFML/System/Vector2.hpp>

using namespace GameEngine;

CreateBricksComponent::CreateBricksComponent()
{

}
CreateBricksComponent::~CreateBricksComponent()
{

}
void CreateBricksComponent::Run(int iterations)
{
	Entity* brick = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(GetEntity()->GetPos() + sf::Vector2f(GetEntity()->GetSize().x/2.f + 25 + iterations*50,0)), sf::Vector2f(70, 50), sf::Color::Blue);
	GameEngine::BlockCreationManager::CreateText(brick, "Brick", 20, sf::Color::White);
	brick->AddComponent<CollidablePushComponent>();
	bricks.push_back(brick);
}