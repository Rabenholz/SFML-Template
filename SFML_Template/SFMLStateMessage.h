#pragma once
#include <SFML/Window.hpp>

enum SFMLStateMessageType
{
	None = 0,
	Close,
	Resize,
	ChangeState,
	PushState,
	PopState,
	RemoveState,
	TypeCount
};

class SFMLStateMessage
{
protected:
	//SFMLStateMessage():m_type(None) {}
	SFMLStateMessage(SFMLStateMessageType type):type(type) {}
public:
	virtual ~SFMLStateMessage(void) {}
	const SFMLStateMessageType getType(void) {return type;}

private:
	const SFMLStateMessageType type;
};

class SFMLStateMessage_Close : public SFMLStateMessage
{
public:
	SFMLStateMessage_Close(void):SFMLStateMessage(Close) {}
	virtual ~SFMLStateMessage_Close(void) {}
};

class SFMLStateMessage_Resize : public SFMLStateMessage
{
public:
	SFMLStateMessage_Resize(int width, int height):SFMLStateMessage(Resize), m_width(width), m_height(height) {}
	virtual ~SFMLStateMessage_Resize(void) {}
	int m_width;
	int m_height;
};

class SFMLStateMessage_ChangeState : public SFMLStateMessage
{
public:
	SFMLStateMessage_ChangeState(std::string stateIdentifier):SFMLStateMessage(ChangeState), m_stateID(stateIdentifier) {}
	virtual ~SFMLStateMessage_ChangeState(void) {}
	std::string m_stateID;
};

class SFMLStateMessage_PushState : public SFMLStateMessage
{
public:
	SFMLStateMessage_PushState(std::string stateIdentifier):SFMLStateMessage(PushState), m_stateID(stateIdentifier) {}
	virtual ~SFMLStateMessage_PushState(void) {}
	std::string m_stateID;
};

class SFMLStateMessage_PopState : public SFMLStateMessage
{
public:
	SFMLStateMessage_PopState(void):SFMLStateMessage(PopState){}
	virtual ~SFMLStateMessage_PopState(void) {}
};

class SFMLStateMessage_RemoveState : public SFMLStateMessage
{
public:
	SFMLStateMessage_RemoveState(std::string stateIdentifier):SFMLStateMessage(RemoveState), m_stateID(stateIdentifier) {}
	virtual ~SFMLStateMessage_RemoveState(void) {}
	std::string m_stateID;
};