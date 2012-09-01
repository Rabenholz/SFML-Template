#pragma once
#include "Functor.h"
#include <SFML/Graphics.hpp>

class SFMLGUIElement
	:public sf::Drawable, public sf::Transformable
{
public:
	SFMLGUIElement(void);
	~SFMLGUIElement(void);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates) const = 0;
	virtual sf::FloatRect getLocalBounds(void) const = 0;
	virtual sf::FloatRect getGlobalBounds(void) const = 0;

	void OnMouseLeftPressed(void);
	void OnMouseLeftReleased(void);
	void OnMouseRightPressed(void);
	void OnMouseRightReleased(void);
	void OnMouseMiddlePressed(void);
	void OnMouseMiddleReleased(void);

	//turn to unclicked, even if the button itself isn't released on
	void OnGlobalMouseLeftReleased(void);
	void OnGlobalMouseRightReleased(void);
	void OnGlobalMouseMiddleReleased(void);

	void setMouseLeftPressedFunction(TFunctorBase* func) {m_MouseLeftPressedfunc = func;}
	void setMouseLeftReleasedFunction(TFunctorBase* func) {m_MouseLeftReleasedfunc = func;}
	void setMouseRightPressedFunction(TFunctorBase* func) {m_MouseRightPressedfunc = func;}
	void setMouseRightReleasedFunction(TFunctorBase* func) {m_MouseRightReleasedfunc = func;}
	void setMouseMiddlePressedFunction(TFunctorBase* func) {m_MouseMiddlePressedfunc = func;}
	void setMouseMiddleReleasedFunction(TFunctorBase* func) {m_MouseMiddleReleasedfunc = func;}
	void setMouseLeftClickedFunction(TFunctorBase* func) {m_MouseLeftClickedfunc = func;}
	void setMouseRightClickedFunction(TFunctorBase* func) {m_MouseRightClickedfunc = func;}
	void setMouseMiddleClickedFunction(TFunctorBase* func) {m_MouseMiddleClickedfunc = func;}
	
protected:
	bool m_leftPressed;
	bool m_rightPressed;
	bool m_middlePressed;

	TFunctorBase* m_MouseLeftPressedfunc;
	TFunctorBase* m_MouseLeftReleasedfunc;
	TFunctorBase* m_MouseRightPressedfunc;
	TFunctorBase* m_MouseRightReleasedfunc;
	TFunctorBase* m_MouseMiddlePressedfunc;
	TFunctorBase* m_MouseMiddleReleasedfunc;
	TFunctorBase* m_MouseLeftClickedfunc;
	TFunctorBase* m_MouseRightClickedfunc;
	TFunctorBase* m_MouseMiddleClickedfunc;
};

