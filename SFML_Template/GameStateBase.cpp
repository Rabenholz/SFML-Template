#include "StdAfx.h"
#include "GameStateBase.h"
#include <algorithm>

GameStateBase::GameStateBase(void)
	:m_transparent(false),
	m_allowSubUpdate(false),
	m_subUpdate(true),
	m_subRender(true)
{
}


GameStateBase::~GameStateBase(void)
{
}

void GameStateBase::drawDisplayList(sf::RenderTarget& target) const
{
	for(std::vector<sf::Drawable*>::const_iterator dispIt(m_displayList.begin());
		dispIt != m_displayList.end(); dispIt++)
	{
		target.draw(**dispIt);
	}
}

void GameStateBase::OnEvent(sf::Event& Event)
{
	SFMLEvent::OnEvent(Event);
}

void GameStateBase::OnClose(void)
{
	m_messages.push_back(new SFMLStateMessage_Close());
}

void GameStateBase::OnResize(int width, int height)
{
	m_messages.push_back(new SFMLStateMessage_Resize(width, height));
}

SFMLStateMessage* GameStateBase::GetStateMessage(void)
{
	if(m_messages.size() == 0)
		return NULL;
	SFMLStateMessage* retVal(m_messages.back());
	m_messages.pop_back();
	return retVal;
}

const std::vector<sf::Drawable*>& GameStateBase::GetDisplayList(void)
{
	return m_displayList;
}

void GameStateBase::CleanupDisplayList(void)
{
	for(std::vector<sf::Drawable*>::iterator dispIt(m_displayList.begin()); dispIt != m_displayList.end(); dispIt++)
	{
		delete (*dispIt);
	}
	m_displayList.clear();
}

void GameStateBase::addGUIElement(SFMLGUIElement* target)
{
	if(target == NULL)
		return;
	m_GUIElements.push_back(target);
	m_displayList.push_back(target);
}

void GameStateBase::removeGUIElement(SFMLGUIElement* target)
{
	std::vector<SFMLGUIElement*>::iterator guiIt(std::find(m_GUIElements.begin(), m_GUIElements.end(), target));
	if(guiIt != m_GUIElements.end())
	{
		delete *guiIt;
		m_GUIElements.erase(guiIt);
		
		std::vector<sf::Drawable*>::iterator dispIt(std::find(m_displayList.begin(), m_displayList.end(), target));
		if(dispIt != m_displayList.end())
			m_displayList.erase(dispIt);
	}
}

SFMLGUIElement* GameStateBase::getTopGUIElement(int X, int Y)
{
	for(std::vector<SFMLGUIElement*>::reverse_iterator objIt(m_GUIElements.rbegin()); objIt !=  m_GUIElements.rend(); objIt++)
	{
		SFMLGUIElement* guiObj = (*objIt);
		if(pointCollided(guiObj, X, Y))
		{
			return guiObj;
		}
	}
	return NULL;
}

bool GameStateBase::pointCollided(SFMLGUIElement* target, int X, int Y)
{
	//right now we'll just test this with rectangles
	return target->getGlobalBounds().contains(static_cast<float>(X),static_cast<float>(Y));
}

void GameStateBase::MouseEvent_Pressed(sf::Mouse::Button button, int x, int y)
{
	SFMLGUIElement* guiObj = getTopGUIElement(x, y);
	if(guiObj != NULL)
	{
		switch(button)
		{
		case sf::Mouse::Left:
			guiObj->OnMouseLeftPressed();
			break;
		case sf::Mouse::Right:
			guiObj->OnMouseRightPressed();
			break;
		case sf::Mouse::Middle:
			guiObj->OnMouseMiddlePressed();
			break;
		}
	}

}
void GameStateBase::MouseEvent_Released(sf::Mouse::Button button, int x, int y)
{
	SFMLGUIElement* guiObj = getTopGUIElement(x, y);
	if(guiObj != NULL)
	{
		switch(button)
		{
		case sf::Mouse::Left:
			guiObj->OnMouseLeftReleased();
			break;
		case sf::Mouse::Right:
			guiObj->OnMouseRightReleased();
			break;
		case sf::Mouse::Middle:
			guiObj->OnMouseMiddleReleased();
			break;
		}
	}
	//tell all gui objs that the mouse has been released
	for(std::vector<SFMLGUIElement*>::iterator objIt(m_GUIElements.begin()); objIt !=  m_GUIElements.end(); objIt++)
	{
		switch(button)
		{
		case sf::Mouse::Left:
			(*objIt)->OnGlobalMouseLeftReleased();
			break;
		case sf::Mouse::Right:
			(*objIt)->OnGlobalMouseRightReleased();
			break;
		case sf::Mouse::Middle:
			(*objIt)->OnGlobalMouseMiddleReleased();
			break;
		}
	}
}
void GameStateBase::MouseEvent_Moved(sf::Mouse::Button button, int x, int y)
{
}

void GameStateBase::CleanupGUIElements(void)
{
	while(m_GUIElements.size() > 0)
	{
		removeGUIElement(m_GUIElements.front());
	}
	m_GUIElements.clear();
}
/*
void GameStateBase::CleanupMouseListeners(void)
{
	for(int i = 0; i<MOUSEEVENTCOUNT; i++)
	{
		m_mouseListeners[i].clear();
	}
}
*/