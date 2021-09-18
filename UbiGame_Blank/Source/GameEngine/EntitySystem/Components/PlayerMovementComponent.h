#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace GameEngine
{
	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		PlayerMovementComponent();
		~PlayerMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;
	};
}