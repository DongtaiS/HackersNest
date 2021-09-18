#include "ForLoopBlock.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
using namespace GameEngine;

void ForLoopBlock::Execute()
{
	sf::Clock clock;
	for (int i = 0; i < iterations; i++)
	{
		method.Run(i);
		//while (clock.getElapsedTime().asMilliseconds() < sf::milliseconds(100))
		//{
		//}
		//clock.restart();
	}
}