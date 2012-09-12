#include "StdAfx.h"
#include "SpriteManager.h"

SpriteManager* s_SpriteManager = nullptr;
sf::Sprite* s_SpriteNotFound = nullptr;

SpriteManager::SpriteManager(void)
{
}


SpriteManager::~SpriteManager(void)
{
}

SpriteManager& SpriteManager::getInstance()
{
	if(s_SpriteManager == NULL)
	{
		s_SpriteManager = new SpriteManager();
		if(s_SpriteNotFound == NULL)
		{
			s_SpriteNotFound = new sf::Sprite(TextureManager::getInstance().getTexture("TEXTURENOTFOUND"));
		}
	}
	return *s_SpriteManager;
}
const sf::Sprite& SpriteManager::getSprite(const std::string& spriteID) const
{
	std::map<std::string, sf::Sprite>::const_iterator spriteIt(m_sprites.find(spriteID));
	if(spriteIt == m_sprites.end())
	{
		printf("SPRITE \"%s\" NOT FOUND\n", spriteID.c_str());
		return *s_SpriteNotFound;
	}
		else
			return spriteIt->second;
}
void SpriteManager::addSprite(const sf::Sprite& sprite, const std::string& spriteID)
{
	m_sprites[spriteID] = sprite;
}
void SpriteManager::removeSprite(const std::string& spriteID)
{
	m_sprites.erase(spriteID);
}
void SpriteManager::clearSprites(void)
{
	m_sprites.clear();
}

void SpriteManager::cleanup(void)
{
	if(s_SpriteManager != NULL)
	{
		delete s_SpriteManager;
		s_SpriteManager = NULL;
	}
	if(s_SpriteNotFound != NULL)
	{
		delete s_SpriteNotFound;
		s_SpriteNotFound = NULL;
	}
}