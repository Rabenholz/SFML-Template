#include "StdAfx.h"
#include "GameState_Game1.h"


GameState_Game1::GameState_Game1(void)
{
	m_transparent = false;
	m_allowSubUpdate = false;
	m_subUpdate = true;
	m_subRender = true;
}


GameState_Game1::~GameState_Game1(void)
{
}

void GameState_Game1::OnAwake(void)
{
	std::unique_ptr<sf::CircleShape> circle(new sf::CircleShape(150.0f));
	circle->setPosition(sf::Vector2f(400,300));
	circle->setFillColor(sf::Color::Yellow);
	circle->setOutlineThickness(2.0f);
	circle->setOutlineColor(sf::Color::White);
	addDrawable(std::move(circle));
}

void GameState_Game1::OnUpdate(void)
{
}

void GameState_Game1::OnCleanup(void)
{
	GameStateBase::Cleanup();
}

void GameState_Game1::OnSuspend(void)
{
}

void GameState_Game1::OnResume(void)
{
}

void GameState_Game1::OnKeyPressed(sf::Keyboard::Key key, bool alt, bool control, bool shift)
{
	switch(key)
	{
	case sf::Keyboard::Escape:
		m_messages.push_back(new SFMLStateMessage_PushState("PauseState"));
		break;
	case sf::Keyboard::X:
		m_messages.push_back(new SFMLStateMessage_ChangeState("MenuState"));
		break;
	}
}