#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/BlockCreationManager.h"
#include "GameEngine/EntitySystem/Components/ForLoopBlock.h"
#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePushComponent.h"
#include "GameEngine/EntitySystem/Components/CreateBrickComponent.h"
#include "GameEngine/EntitySystem/Components/EndComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/EntitySystem/Components/PhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine\EntitySystem\Components\BallMoveButton.h"
#include <iostream>
#include <vector>
using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateBlock();
	GameEngine::Entity* floor = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(100, 400), sf::Vector2f(300, 50), sf::Color::White);
	floor->AddComponent<GameEngine::CollidablePhysicsComponent>();

	GameEngine::Entity* forLoopBlock = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(50, 200), sf::Vector2f(100, 50), sf::Color::Red);
	GameEngine::BlockCreationManager::CreateText(forLoopBlock, "for: 3", 20, sf::Color::White);
	GameEngine::ForLoopBlock* forLoop = static_cast<GameEngine::ForLoopBlock*>(forLoopBlock->AddComponent<GameEngine::ForLoopBlock>());

	GameEngine::Entity* brickCreator = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(50, 250), sf::Vector2f(175, 50), sf::Color::Red);
	GameEngine::BlockCreationManager::CreateText(brickCreator, "createbrick()", 20, sf::Color::White);
	GameEngine::CreateBricksComponent* brickComp = static_cast<GameEngine::CreateBricksComponent*>(brickCreator->AddComponent<GameEngine::CreateBricksComponent>());
	brickCreator->AddComponent<GameEngine::CollidablePhysicsComponent>();

	GameEngine::Entity* ballButton = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(475, 25), sf::Vector2f(50, 50), sf::Color::Green);
	
	ballButton->AddComponent<GameEngine::BallMoveButton>()->SetBallPhysicsComp(m_player->GetComponent<GameEngine::PhysicsComponent>());

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetSize(sf::Vector2f(50,50));
	m_player->SetPos(sf::Vector2f(10, 10));
	m_player->AddComponent<GameEngine::PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::PhysicsComponent>();
	GameEngine::SpriteRenderComponent* sprite = static_cast<GameEngine::SpriteRenderComponent*>(m_player->AddComponent<GameEngine::SpriteRenderComponent>());
	sprite->SetTexture(GameEngine::eTexture::Player);
	sprite->SetFillColor(sf::Color::Transparent);
}

void GameBoard::CreateBlock()
{
	m_block = GameEngine::BlockCreationManager::CreateBlock(sf::Vector2f(20, 300), sf::Vector2f(50, 50), sf::Color::Blue);
	GameEngine::CreateBricksComponent* createBrickComp = static_cast<GameEngine::CreateBricksComponent*>(m_block->AddComponent<GameEngine::CreateBricksComponent>());



	std::cout << m_player->GetAllComponents<GameEngine::Component>().size();
	GameEngine::EndComponent* end = static_cast<GameEngine::EndComponent*>(m_block->AddComponent<GameEngine::EndComponent>());
	end->SetPlayerCollider(m_player->GetComponent<GameEngine::CollidableComponent>());

	GameEngine::BlockCreationManager::CreateText(m_block, "Goal", 20, sf::Color::White);


}

