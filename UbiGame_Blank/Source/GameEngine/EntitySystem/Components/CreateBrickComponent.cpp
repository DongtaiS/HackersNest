#include "CreateBrickComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePushComponent.h"


using namespace GameEngine;

CreateBricksComponent::CreateBricksComponent()
{

}
CreateBricksComponent::~CreateBricksComponent()
{

}
void CreateBricksComponent::Run(int iterations)
{
	//Create a brick
	m_brick = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_brick);

	m_brick->SetSize(sf::Vector2f(50.0f, 50.0f));
	m_brick->SetPos(sf::Vector2f(GetEntity()->GetPos().x + GetEntity()->GetSize().x/2 + iterations, GetEntity()->GetPos().y + GetEntity()->GetSize().y/2));

	GameEngine::RenderComponent* render = static_cast<GameEngine::RenderComponent*>(m_brick->AddComponent<GameEngine::RenderComponent>());
	m_brick->AddComponent<GameEngine::CollidablePushComponent>();
	render->SetFillColor(sf::Color::Blue);
}