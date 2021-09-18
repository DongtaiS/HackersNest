#include "BlockCreationManager.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h";
#include "GameEngine/GameEngineMain.h"
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
	GameEngineMain::GetInstance()->AddEntity(entity);
	return entity;
}

TextRenderComponent* BlockCreationManager::CreateText(Entity* entity, std::string str, int size, sf::Color color)
{
	TextRenderComponent* text = static_cast<TextRenderComponent*>(entity->AddComponent<TextRenderComponent>());
	text->SetString(str);
	text->SetFont("Avant_Garde.ttf");
	text->SetCharacterSizePixels(size);
	text->SetColor(color);
	text->SetFillColor(sf::Color::Transparent);
	return text;
}

BlockCreationManager::BlockCreationManager()
{
}