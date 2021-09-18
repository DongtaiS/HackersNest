#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/System/Vector2.hpp>
namespace GameEngine
{
	class PhysicsComponent : public GameEngine::Component
	{
	public:
		PhysicsComponent();
		~PhysicsComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;
	private:
		sf::Vector2f m_velocity;
		sf::Vector2f m_wantedVelocity;
	};
}