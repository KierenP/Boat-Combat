#pragma once
#include "SFML\Graphics.hpp"

class iRendableObj : public sf::Drawable, public sf::Transformable
{
public:
	iRendableObj();
	virtual ~iRendableObj();



protected:
	sf::VertexArray m_vertices;
	sf::Texture m_texture;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

