#include "EndComponent.h"
#include "Game/GameBoard.h"

#include "CollidablePushComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"


#include <vector>
#include <iostream>



using namespace GameEngine;

EndComponent::EndComponent()
{
}

EndComponent::~EndComponent()
{

}

void EndComponent::SetPlayerCollider(CollidableComponent* playerCollider)
{
	m_player = playerCollider;
}

void EndComponent::Update()
{
	AABBRect intersection;
	AABBRect myBox = GetWorldAABB();
	AABBRect colideBox = m_player->GetWorldAABB();
	if (myBox.intersects(colideBox, intersection))
	{
		std::cout << "test";
	}
}