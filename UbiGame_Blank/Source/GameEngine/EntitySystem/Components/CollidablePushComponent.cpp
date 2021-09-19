#include "CollidablePushComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <vector>
#include <iostream>

using namespace GameEngine;

CollidablePushComponent::CollidablePushComponent()
{

}


CollidablePushComponent::~CollidablePushComponent()
{

}


void CollidablePushComponent::OnAddToWorld()
{
	CollidableComponent::OnAddToWorld();
}


void CollidablePushComponent::OnRemoveFromWorld()
{
	CollidableComponent::OnRemoveFromWorld();
}


void CollidablePushComponent::Update()
{
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();

	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;

		AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			OnCollide(colComponent);
			colComponent->OnCollide(this);
			sf::Vector2f pos = sf::Vector2f(0,0);
			if (intersection.width < intersection.height)
			{
				if (myBox.left < colideBox.left)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
			}
			else
			{
				if (myBox.top < colideBox.top)
					pos.y -= intersection.height;
				else if (myBox.top > colideBox.top)
					pos.y += intersection.height;
			}
			GetEntity()->SetPos(GetEntity()->GetPos() + pos);
		}
	}
}