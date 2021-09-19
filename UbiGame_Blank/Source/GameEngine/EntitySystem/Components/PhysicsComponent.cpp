#include "PhysicsComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"
#include <iostream>
using namespace GameEngine;

PhysicsComponent::PhysicsComponent()
{

}

PhysicsComponent::~PhysicsComponent()
{

}

void PhysicsComponent::OnAddToWorld()
{
    CollidablePhysicsComponent::OnAddToWorld();
}

void PhysicsComponent::Update()
{
    if (isActive)
    {
        float dt = GameEngine::GameEngineMain::GetTimeDelta();
        float currentY = GetEntity()->GetPos().y;

        float gForce = 750.f;

        if (dt > 0.f)
        {
            m_velocity.x = m_wantedVelocity.x;
            m_velocity.y += m_wantedVelocity.y;
            m_velocity.y += gForce * dt;
            sf::Vector2f deltavelocity = dt * m_velocity;
            GetEntity()->SetPos(GetEntity()->GetPos() + deltavelocity);
        }

        CollidablePhysicsComponent::Update();

        float deltaY = GetEntity()->GetPos().y - currentY;
        if (dt > 0.f && deltaY >= 0)
        {
            m_velocity.y = deltaY / dt;
        }
    }
    else
    {
        CollidablePhysicsComponent::Update();
    }
}