#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
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

	m_player->SetPos(sf::Vector2f(10.0f, 10.0f));            // <-- Give the position 10,10 to the entity
	m_player->SetSize(sf::Vector2f(10.0f, 10.0f));           // <-- Give the size 10,10 to the entity

	m_player->AddComponent<GameEngine::RenderComponent>();   // <-- Add a RenderComponent to the entity
}