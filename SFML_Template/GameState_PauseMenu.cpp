#include "StdAfx.h"
#include "GameState_PauseMenu.h"


GameState_PauseMenu::GameState_PauseMenu(const sf::Window& window)
	:GameStateBase(window)
{
	m_transparent = true;
	m_allowSubUpdate = false;
	m_subUpdate = true;
	m_subRender = true;
}


GameState_PauseMenu::~GameState_PauseMenu(void)
{
}

void GameState_PauseMenu::OnAwake(const SFMLStateInfo* lStateInfo)
{
	std::unique_ptr<sf::RectangleShape> rect(new sf::RectangleShape(sf::Vector2f(600.0f, 200.0f)));
	rect->setPosition(sf::Vector2f(100.0f, 100.0f));
	rect->setFillColor(sf::Color::White);
	rect->setOutlineThickness(5.0f);
	rect->setOutlineColor(sf::Color::Red);
	addDrawable(std::move(rect));
}

void GameState_PauseMenu::OnUpdate(void)
{
}

void GameState_PauseMenu::OnRender(sf::RenderTarget& target)
{
	GameStateBase::drawDisplayList(target);
}

void GameState_PauseMenu::OnCleanup(void)
{
	GameStateBase::Cleanup();
}

void GameState_PauseMenu::OnSuspend(void)
{
}

void GameState_PauseMenu::OnResume(void)
{
}

void GameState_PauseMenu::OnKeyPressed(sf::Keyboard::Key key, bool alt, bool control, bool shift)
{
	switch(key)
	{
	case sf::Keyboard::Escape:
		m_messages.push_back(new SFMLStateMessage_PopState());
		break;
	}
}