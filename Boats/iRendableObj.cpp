#include "iRendableObj.h"



iRendableObj::iRendableObj()
{
}


iRendableObj::~iRendableObj()
{
}

void iRendableObj::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform(); 
	states.texture = &m_texture;
	target.draw(m_vertices, states);
}
