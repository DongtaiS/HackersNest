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
            click;
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
        if (rect.contains(mousePos) && click)
        {
            m_clickedEntity = entity;
            m_mouseDownPos = mousePos;
        }
    }

    if (m_isMouseDown)
    {
        if(m_clickedEntity)
        {
            m_clickedEntity->SetPos(m_clickedEntity->GetPos() + (mousePos - m_mouseDownPos));
        }

    }

}

MouseManager::MouseManager()
{

}