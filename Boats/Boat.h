#pragma once
#include <SFML\Graphics.hpp>
#include <string.h>
#include <math.h>   
#include "iPhysicsComponent.h"
#include "iSFMLDrawable.h"

enum TurnDelta
{
	LEFT = -1,		//-1
	STRAIGHT,		// 0
	RIGHT,			// 1
};

enum ThrustDelta
{
	BACK = -1,		//-1
	NONE,			// 0
	FOWARD,		    // 1
};

class Boat : public iPhysicsComponent, public sf::Drawable
{
public:
	Boat();
	~Boat();

	void Update(float dTime);
	
	//Getters
	sf::Sprite GetSprite() { return m_sprite; }

	void SetSprite(sf::Sprite val) { m_sprite = val; }
	void SetTexture(sf::Texture val);
	void SetTexture(std::string address);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

