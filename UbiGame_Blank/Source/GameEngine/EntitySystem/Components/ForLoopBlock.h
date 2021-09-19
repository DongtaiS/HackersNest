#pragma once
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/MethodBlockComponent.h"
namespace GameEngine
{
	class ForLoopBlock : public GameEngine::CollidableComponent
	{
	public:
		ForLoopBlock();
		~ForLoopBlock();
		int iterations = 3;
		void Execute();
		void SetMethodBlock(MethodBlockComponent* methodBlock) { method = methodBlock; }
		virtual void OnCollide(CollidableComponent* otherCollider) override;
	private:
		MethodBlockComponent* method;
	};
}
