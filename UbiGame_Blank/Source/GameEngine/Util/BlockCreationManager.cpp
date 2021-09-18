#include "BlockCreationManager.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h";
using namespace GameEngine;

BlockCreationManager::~BlockCreationManager()
{

}
void BlockCreationManager::Update()
{
}
Entity* BlockCreationManager::CreateBlock(sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
	Entity* entity = new Entity();
	entity->SetPos(pos);
	entity->SetSize(size);
	RenderComponent* render = static_cast<RenderComponent*>(entity->AddComponent<RenderComponent>());
	render->SetFillColor(color);
	return entity;
}
BlockCreationManager::BlockCreationManager()
{
}