#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include <vector>
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

namespace GameEngine
{
	class MouseManager
	{
		public:
			~MouseManager();
			void Update();
			static MouseManager* GetInstance() { if (!sm_instance) sm_instance = new MouseManager(); return sm_instance; }

		private:
			MouseManager();
			static MouseManager* sm_instance;
			bool m_isMouseDown = false;
			GameEngine::Entity* m_clickedEntity = nullptr;
			sf::Vector2f m_mouseDownPos;
			sf::Vector2f m_clickedEntityPos;
		};
}
