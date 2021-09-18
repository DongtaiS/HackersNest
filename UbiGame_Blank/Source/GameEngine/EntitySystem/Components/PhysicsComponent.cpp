#include "PhysicsComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"

using namespace GameEngine;

PhysicsComponent::PhysicsComponent()
{

}

PhysicsComponent::~PhysicsComponent()
{

}

void PhysicsComponent::OnAddToWorld()
{
    //    GameEngine::Component::OnAddToWorld();
    Component::OnAddToWorld();
}

void PhysicsComponent::Update()
{
    float dt = GameEngine::GameEngineMain::GetTimeDelta();
    float currentY = GetEntity()->GetPos().y;

    float gForce = 0.1f;

    if (dt > 0.f)
    {
        m_velocity.x = m_wantedVelocity.x;
        m_velocity.y += gForce * dt;
        sf::Vector2f deltavelocity = dt * m_velocity;
        GetEntity()->SetPos(GetEntity()->GetPos() + deltavelocity);
    }

    Component::Update();

    float deltaY = GetEntity()->GetPos().y + currentY;
    if (dt > 0.f)
    {
        m_velocity.y = deltaY / dt;
    }
}