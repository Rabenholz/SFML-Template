#include "StdAfx.h"
#include "AnimatedButton.h"


AnimatedButton::AnimatedButton(void)
	:SFMLGUIElement(),
	 m_unpressedAnimatedSprite(NULL),
	 m_pressedAnimatedSprite(NULL)
{
}

AnimatedButton::AnimatedButton(AnimatedSprite* unpressedAnimatedSprite)
	:SFMLGUIElement(),
	m_unpressedAnimatedSprite(unpressedAnimatedSprite),
	m_pressedAnimatedSprite(NULL)
{
	m_unpressedAnimatedSprite->Play();
}

AnimatedButton::AnimatedButton(AnimatedSprite* unpressedAnimatedSprite, AnimatedSprite* pressedAnimatedSprite)
	:SFMLGUIElement(),
	m_unpressedAnimatedSprite(unpressedAnimatedSprite),
	m_pressedAnimatedSprite(pressedAnimatedSprite)
{
	m_unpressedAnimatedSprite->Play();
	m_pressedAnimatedSprite->Play();
}

AnimatedButton::~AnimatedButton(void)
{

}

void AnimatedButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	if(m_pressedAnimatedSprite &&(m_leftPressed || m_middlePressed || m_rightPressed))
		target.draw(*m_pressedAnimatedSprite, states);
	else if(m_unpressedAnimatedSprite)
		target.draw(*m_unpressedAnimatedSprite, states);
}

sf::FloatRect AnimatedButton::getLocalBounds(void) const
{
	if(m_pressedAnimatedSprite &&(m_leftPressed || m_middlePressed || m_rightPressed))
		return m_pressedAnimatedSprite->getLocalBounds();
	else if(m_unpressedAnimatedSprite)
		return m_unpressedAnimatedSprite->getLocalBounds();
	else
		return sf::FloatRect();
}

sf::FloatRect AnimatedButton::getGlobalBounds(void) const
{
	if(m_pressedAnimatedSprite &&(m_leftPressed || m_middlePressed || m_rightPressed))
		return getTransform().transformRect(m_pressedAnimatedSprite->getGlobalBounds());
	else if(m_unpressedAnimatedSprite)
		return getTransform().transformRect(m_unpressedAnimatedSprite->getGlobalBounds());
	else
		return sf::FloatRect();
}

void AnimatedButton::setUnpressedAnimatedSprite(AnimatedSprite* animatedSprite)
{
	delete m_unpressedAnimatedSprite;
	m_unpressedAnimatedSprite = animatedSprite;
	m_unpressedAnimatedSprite->Play();
}

void AnimatedButton::setPressedAnimatedSprite(AnimatedSprite* animatedSprite)
{
	delete m_pressedAnimatedSprite;
	m_pressedAnimatedSprite = animatedSprite;
	m_pressedAnimatedSprite->Play();
}
AnimatedSprite* AnimatedButton::getUnpressedAnimatedSprite(void) const
{
	return m_unpressedAnimatedSprite;
}

AnimatedSprite* AnimatedButton::getPressedAnimatedSprite(void) const
{
	return m_pressedAnimatedSprite;
}