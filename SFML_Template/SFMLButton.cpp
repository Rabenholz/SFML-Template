#include "StdAfx.h"
#include "SFMLButton.h"


SFMLButton::SFMLButton(void)
	:SFMLGUIElement(),
	 m_unpressedSprite(NULL),
	 m_pressedSprite(NULL)
{
}

SFMLButton::SFMLButton(sf::Sprite* unpressedSprite)
	:SFMLGUIElement(),
	m_unpressedSprite(unpressedSprite),
	m_pressedSprite(NULL)
{
}

SFMLButton::SFMLButton(sf::Sprite* unpressedSprite, sf::Sprite* pressedSprite)
	:SFMLGUIElement(),
	m_unpressedSprite(unpressedSprite),
	m_pressedSprite(pressedSprite)
{
}

SFMLButton::~SFMLButton(void)
{
	delete m_unpressedSprite;
	delete m_pressedSprite;
}

void SFMLButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	if(m_pressedSprite &&(m_leftPressed || m_middlePressed || m_rightPressed))
		target.draw(*m_pressedSprite, states);
	else if(m_unpressedSprite)
		target.draw(*m_unpressedSprite, states);
}

sf::FloatRect SFMLButton::getLocalBounds(void) const
{
	if(m_pressedSprite &&(m_leftPressed || m_middlePressed || m_rightPressed))
		return m_pressedSprite->getLocalBounds();
	else if(m_unpressedSprite)
		return m_unpressedSprite->getLocalBounds();
	else
		return sf::FloatRect();
}

sf::FloatRect SFMLButton::getGlobalBounds(void) const
{
	if(m_pressedSprite &&(m_leftPressed || m_middlePressed || m_rightPressed))
		return getTransform().transformRect(m_pressedSprite->getGlobalBounds());
	else if(m_unpressedSprite)
		return getTransform().transformRect(m_unpressedSprite->getGlobalBounds());
	else
		return sf::FloatRect();
}

void SFMLButton::setUnpressedSprite(sf::Sprite* sprite)
{
	delete m_unpressedSprite;
	m_unpressedSprite = sprite;
}

void SFMLButton::setPressedSprite(sf::Sprite* sprite)
{
	delete m_pressedSprite;
	m_pressedSprite = sprite;
}

sf::Sprite* SFMLButton::getUnpressedSprite(void) const
{
	return m_unpressedSprite;
}

sf::Sprite* SFMLButton::getPressedSprite(void) const
{
	return m_pressedSprite;
}