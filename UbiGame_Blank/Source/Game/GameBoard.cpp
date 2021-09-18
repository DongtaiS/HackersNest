#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
{

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

	m_player->SetPos(sf::Vector2f(10.0f, 10.0f));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	GameEngine::RenderComponent* render = static_cast<GameEngine::RenderComponent*>(m_player->AddComponent<GameEngine::RenderComponent>());

	render->SetFillColor(sf::Color::Red);
}