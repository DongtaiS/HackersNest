#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/BlockCreationManager.h"
#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePushComponent.h"
#include "GameEngine/EntitySystem/Components/CreateBrickComponent.h"
#include "GameEngine/EntitySystem/Components/EndComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/EntitySystem/Components/PhysicsComponent.h"
#include <iostream>
#include <vector>
using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateBlock();
	GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(0, 400), sf::Vector2f(500, 50), sf::Color::White);
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreatePlayer()
{
	m_player = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(10, 10), sf::Vector2f(200, 200), sf::Color::Red);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->AddComponent<GameEngine::PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::CollidableComponent>();
	m_player->AddComponent<GameEngine::PhysicsComponent>();
}

void GameBoard::CreateBlock()
{
	m_block = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(20, 300), sf::Vector2f(50, 50), sf::Color::Blue);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_block);
	//m_block->AddComponent<GameEngine::CollidableComponent>();
	GameEngine::CreateBricksComponent* createBrickComp = static_cast<GameEngine::CreateBricksComponent*>(m_block->AddComponent<GameEngine::CreateBricksComponent>());

	std::cout << m_player->GetAllComponents<GameEngine::Component>().size();
	GameEngine::EndComponent* end = static_cast<GameEngine::EndComponent*>(m_block->AddComponent<GameEngine::EndComponent>());
	end->SetPlayerCollider(m_player->GetComponent<GameEngine::CollidableComponent>());

	GameEngine::BlockCreationManager::CreateText(m_block, "GOAL", 20, sf::Color::White);

}

