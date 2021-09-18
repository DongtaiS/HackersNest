#pragma once
#include "GameEngine/EntitySystem/Components/MethodBlockComponent.h"
class CreateBricksComponent : public GameEngine::MethodBlockComponent
{
public:
	CreateBricksComponent();
	~CreateBricksComponent();
	virtual void Run() override;
};

