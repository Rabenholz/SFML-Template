#pragma once
#include "sfmlguielement.h"
#include "AnimatedSprite.h"
class AnimatedButton :
	public SFMLGUIElement
{
public:
	AnimatedButton(void);
	AnimatedButton::AnimatedButton(AnimatedSprite* unpressedAnimatedSprite);
	AnimatedButton::AnimatedButton(AnimatedSprite* unpressedAnimatedSprite, AnimatedSprite* pressedAnimatedSprite);

	virtual ~AnimatedButton(void);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getLocalBounds(void) const;
	virtual sf::FloatRect getGlobalBounds(void) const;

	void setUnpressedAnimatedSprite(AnimatedSprite* animatedSprite);
	void setPressedAnimatedSprite(AnimatedSprite* animatedSprite);
	AnimatedSprite* getUnpressedAnimatedSprite(void) const;
	AnimatedSprite* getPressedAnimatedSprite(void) const;

protected:
	AnimatedSprite* m_unpressedAnimatedSprite;
	AnimatedSprite* m_pressedAnimatedSprite;
};

