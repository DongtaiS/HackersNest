#pragma once
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class EndComponent : public CollidableComponent
	{
		CollidableComponent* m_player = nullptr;

	public:
		virtual void Update() override;
		void SetPlayerCollider(CollidableComponent* playerCollider);
		EndComponent(); 
		~EndComponent();
	};
}

