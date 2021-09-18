#include "MouseManager.h"
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
        m_clickedEntity = nullptr;
    }

    std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();
    for (int a = 0; a < collidables.size(); ++a)
    {
        CollidableComponent* colComponent = collidables[a];
        GameEngine::Entity* entity = colComponent->GetEntity();
        sf::Vector2 topLeft = entity->GetPos() - entity->GetSize()/2.f;
        sf::Rect rect = sf::Rect(topLeft, entity->GetSize());
        if (rect.contains(mousePos) && click)
        {
            m_clickedEntity = colComponent->GetEntity();
            m_mouseDownPos = mousePos;
            m_clickedEntityPos = colComponent->GetEntity()->GetPos();
        }
    }

    if (m_isMouseDown && m_clickedEntity)
    {
        m_clickedEntity->SetPos(m_clickedEntityPos + (mousePos - m_mouseDownPos));
    }

}


MouseManager::MouseManager()
{

}