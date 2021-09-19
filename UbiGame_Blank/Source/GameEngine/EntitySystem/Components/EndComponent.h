#pragma once
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class EndComponent : public CollidableComponent
	{
		CollidableComponent* m_playerCollider = nullptr;

	public:
		virtual void OnCollide(CollidableComponent* otherCollider) override;
		void SetPlayerCollider(CollidableComponent* playerCollider);
		EndComponent(); 
		~EndComponent();
	};
}

