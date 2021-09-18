#include "ForLoopBlock.h"
using namespace GameEngine;

void ForLoopBlock::Execute()
{
	for (int i = 0; i < iterations; i++)
	{
		method.run();
	}
}