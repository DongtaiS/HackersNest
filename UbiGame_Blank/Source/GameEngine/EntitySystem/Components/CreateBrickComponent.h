#pragma once
#include "GameEngine/EntitySystem/Components/MethodBlockComponent.h"
namespace GameEngine
{
	class CreateBricksComponent : public GameEngine::MethodBlockComponent
	{
	public:
		CreateBricksComponent();
		~CreateBricksComponent();
		virtual void Run(int iterations) override;
		GameEngine::Entity* m_brick;
	};
}

