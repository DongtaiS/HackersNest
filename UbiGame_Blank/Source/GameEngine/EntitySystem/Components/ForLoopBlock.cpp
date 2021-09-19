#include "ForLoopBlock.h"
#include "GameEngine\EntitySystem\Entity.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
using namespace GameEngine;


ForLoopBlock::ForLoopBlock()
{

}
ForLoopBlock::~ForLoopBlock()
{

}
void ForLoopBlock::Execute()
{
	sf::Clock clock;
	for (int i = 0; i < iterations; i++)
	{
		method->Run(i);
		//while (clock.getElapsedTime().asMilliseconds() < sf::milliseconds(100))
		//{
		//}
		//clock.restart();
	}
}
void ForLoopBlock::OnCollide(CollidableComponent* otherCollider)
{
	MethodBlockComponent* methodBlock = otherCollider->GetEntity()->GetComponent<MethodBlockComponent>();
	if (methodBlock && methodBlock != method)
	{
		SetMethodBlock(methodBlock);
		Execute();
	}
}