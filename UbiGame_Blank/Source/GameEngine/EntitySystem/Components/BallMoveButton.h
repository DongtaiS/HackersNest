#pragma once
#include "GameEngine\EntitySystem\Components\ButtonComponent.h"
#include "GameEngine\EntitySystem\Components\PhysicsComponent.h"
namespace GameEngine
{
	class BallMoveButton : public ButtonComponent
	{
	public:
		BallMoveButton();
		~BallMoveButton();
		virtual void OnButtonClicked() override;
		void SetBallPhysicsComp(PhysicsComponent* physicsComp) { ball = physicsComp; }
	private:
		PhysicsComponent* ball;
	};
}

