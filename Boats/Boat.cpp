#include "Boat.h"

Boat::Boat() : iPhysicsComponent()
{

}


Boat::~Boat()
{

}

void Boat::Update(float dTime)
{
	ThrustDelta thrust = NONE;
	TurnDelta turn = STRAIGHT;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		turn = LEFT;		//-1
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		turn = RIGHT;		//+1
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		thrust = FOWARD;	//+1

	//m_Position += m_Velocity * (dTime * thrust);
	m_Acceleration = Physics::PolarToCartesian(m_Angle, thrust * 1);	//Arbitrary constant of thrust, 1
	m_AngularAcceleration = turn * 0.035;								//Arbitrary constant of torque, 0.035

	//Update the ships phyics engine
	UpdatePhysics(dTime);

	//Update the sfml visuals of the ship
	m_sprite.setPosition(m_Position);
	m_sprite.setRotation(m_Angle / 3.14159 * 180 + 90);

	//Make velocity have the same magnitude as before, but face in the direction of 'direction'
	m_Velocity = Physics::PolarToCartesian(m_Angle, Physics::CartesianToMagnitude(m_Velocity));
}

void Boat::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

void Boat::SetTexture(sf::Texture val)
{
	m_texture = val;
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}

void Boat::SetTexture(std::string address)
{
	m_texture.loadFromFile(address);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}
