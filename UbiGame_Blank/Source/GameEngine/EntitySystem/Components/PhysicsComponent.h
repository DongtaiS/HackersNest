#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include <SFML/System/Vector2.hpp>
namespace GameEngine
{
	class PhysicsComponent : public GameEngine::CollidablePhysicsComponent
	{
	public:
		PhysicsComponent();
		~PhysicsComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;
		void SetVelocity(sf::Vector2f vel) { m_wantedVelocity = vel; }
	private:
		sf::Vector2f m_velocity = sf::Vector2f(0, 0);
		sf::Vector2f m_wantedVelocity = sf::Vector2f(0,0);
		sf::Vector2f m_lastPos;
	};
}