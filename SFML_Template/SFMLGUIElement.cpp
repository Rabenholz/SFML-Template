#include "StdAfx.h"
#include "SFMLGUIElement.h"


SFMLGUIElement::SFMLGUIElement(void)
	:sf::Drawable(), sf::Transformable(),
	 m_leftPressed(false), m_rightPressed(false), m_middlePressed(false),
	 m_MouseLeftPressedfunc(NULL), m_MouseLeftReleasedfunc(NULL),
	 m_MouseRightPressedfunc(NULL), m_MouseRightReleasedfunc(NULL),
	 m_MouseMiddlePressedfunc(NULL), m_MouseMiddleReleasedfunc(NULL),
	 m_MouseLeftClickedfunc(NULL), m_MouseRightClickedfunc(NULL), m_MouseMiddleClickedfunc(NULL)
{
}

SFMLGUIElement::~SFMLGUIElement(void)
{
	delete m_MouseLeftPressedfunc;
	delete m_MouseLeftReleasedfunc;
	delete m_MouseRightPressedfunc;
	delete m_MouseRightReleasedfunc;
	delete m_MouseMiddlePressedfunc;
	delete m_MouseMiddleReleasedfunc;
	delete m_MouseLeftClickedfunc;
	delete m_MouseRightClickedfunc;
	delete m_MouseMiddleClickedfunc;
}

void SFMLGUIElement::OnMouseLeftPressed(void)
{
	m_leftPressed = true;
	if(m_MouseLeftPressedfunc != NULL)
		(*m_MouseLeftPressedfunc)();

}

void SFMLGUIElement::OnMouseLeftReleased(void)
{
	if(m_leftPressed)
	{	
		if(m_MouseLeftClickedfunc != NULL)
			(*m_MouseLeftClickedfunc)();
	}
	else if(m_MouseLeftReleasedfunc != NULL)
		(*m_MouseLeftReleasedfunc)();
}

void SFMLGUIElement::OnMouseRightPressed(void)
{
	m_rightPressed = true;
	if(m_MouseRightPressedfunc != NULL)
		(*m_MouseRightPressedfunc)();
}

void SFMLGUIElement::OnMouseRightReleased(void)
{
	if(m_rightPressed)
	{	
		if(m_MouseRightClickedfunc != NULL)
			(*m_MouseRightClickedfunc)();
	}
	else if(m_MouseRightReleasedfunc != NULL)
		(*m_MouseRightReleasedfunc)();
}

void SFMLGUIElement::OnMouseMiddlePressed(void)
{
	m_middlePressed = true;
	if(m_MouseMiddlePressedfunc != NULL)
		(*m_MouseMiddlePressedfunc)();
}

void SFMLGUIElement::OnMouseMiddleReleased(void)
{
	if(m_middlePressed)
	{	
		if(m_MouseMiddleClickedfunc != NULL)
			(*m_MouseMiddleClickedfunc)();
	}
	else if(m_MouseMiddleReleasedfunc != NULL)
		(*m_MouseMiddleReleasedfunc)();
}

void SFMLGUIElement::OnGlobalMouseLeftReleased(void)
{
	m_leftPressed = false;
}

void SFMLGUIElement::OnGlobalMouseRightReleased(void)
{
	m_rightPressed = false;
}

void SFMLGUIElement::OnGlobalMouseMiddleReleased(void)
{
	m_middlePressed = false;
}
