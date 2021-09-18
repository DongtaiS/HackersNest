#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePushComponent.h"

using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateBlock();
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

	m_player->SetSize(sf::Vector2f(200.0f, 200.0f));
	m_player->SetPos(sf::Vector2f(10.0f, 10.0f));

	GameEngine::RenderComponent* render = static_cast<GameEngine::RenderComponent*>(m_player->AddComponent<GameEngine::RenderComponent>());
	m_player->AddComponent<GameEngine::PlayerMovementComponent>();
	m_player->AddComponent<GameEngine::CollidableComponent>();
	render->SetFillColor(sf::Color::Red);
}

void GameBoard::CreateBlock()
{
	m_block = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_block);

	m_block->SetSize(sf::Vector2f(50.0f, 50.0f));
	m_block->SetPos(sf::Vector2f(300.0f, 10.0f));

	GameEngine::RenderComponent* render = static_cast<GameEngine::RenderComponent*>(m_block->AddComponent<GameEngine::RenderComponent>());
	m_block->AddComponent<GameEngine::CollidablePushComponent>();
	render->SetFillColor(sf::Color::Blue);
}