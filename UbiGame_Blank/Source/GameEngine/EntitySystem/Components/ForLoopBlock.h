#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Component.h"
namespace GameEngine
{
	class ForLoopBlock : public GameEngine::Component
	{
	public:
		ForLoopBlock();
		~ForLoopBlock();
		int iterations;
		MethodBlockComponent method;
		void Execute();

	};
}
