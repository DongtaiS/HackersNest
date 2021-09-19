#pragma once
#include "GameEngine/EntitySystem/Component.h"
namespace GameEngine
{
	class MethodBlockComponent : public GameEngine::Component
	{
	public:
		MethodBlockComponent();
		~MethodBlockComponent();

		virtual void Run(int iterations);
	};
}