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
	m_playerCollider = playerCollider;
}

void EndComponent::OnCollide(CollidableComponent* otherCollider)
{
	if (otherCollider == m_playerCollider)
	{
		std::cout << "playerCollision" << std::endl;
	}
}