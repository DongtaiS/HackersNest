#include "MouseManager.h"
#include <iostream>
using namespace GameEngine;

MouseManager* MouseManager::sm_instance = nullptr;

MouseManager::~MouseManager()
{

}

void MouseManager::Update()
{
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*GameEngine::GameEngineMain::GetInstance()->GetRenderWindow()));
    bool click = false;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!m_isMouseDown)
        {
            click = true;
        }
        m_isMouseDown = true;
    }
    else
    {
        m_isMouseDown = false;
    }

    std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();
    for (int a = 0; a < collidables.size(); ++a)
    {
        CollidableComponent* colComponent = collidables[a];
        GameEngine::Entity* entity = colComponent->GetEntity();
        sf::Vector2 topLeft = sf::Vector2(entity->GetPos().x - entity->GetSize().x / 2, entity->GetPos().y - entity->GetSize().y / 2);
        sf::Rect rect = sf::Rect(topLeft, entity->GetSize());
        std::cout << mousePos.x << " " << mousePos.y << " " << std::to_string(click) << std::endl;
        if (rect.contains(mousePos) && click)
        {
            std::cout << "inside click" << std::endl;
            m_clickedEntity = colComponent->GetEntity();
            m_mouseDownPos = mousePos;
            m_clickedEntityPos = colComponent->GetEntity()->GetPos();
        }
    }

    if (m_isMouseDown && m_clickedEntity)
    {
        std::cout << m_mouseDownPos.x << " " << m_mouseDownPos.y << std::endl;
        m_clickedEntity->SetPos(m_clickedEntityPos + (mousePos - m_mouseDownPos));
    }

    }

}

MouseManager::MouseManager()
{

}