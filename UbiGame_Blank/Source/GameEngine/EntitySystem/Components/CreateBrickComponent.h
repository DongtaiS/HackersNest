#pragma once
#include "GameEngine/EntitySystem/Components/MethodBlockComponent.h"
#include <vector>
namespace GameEngine
{
	class CreateBricksComponent : public GameEngine::MethodBlockComponent
	{
	public:
		CreateBricksComponent();
		~CreateBricksComponent();
		virtual void Run(int iterations) override;
		std::vector<Entity*> bricks;
	};
}

