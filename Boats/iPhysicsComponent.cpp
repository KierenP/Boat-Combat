#include "iPhysicsComponent.h"

iPhysicsComponent::iPhysicsComponent()
{
	m_Acceleration = sf::Vector2f(0, 0);
	m_AngularAcceleration = 0;
	m_AngularVelocity = 0;
	m_Direction = 0;
	m_MoveDrag = 0;
	m_Position = sf::Vector2f(0, 0);
	m_TurnDrag = 0;
	m_Velocity = sf::Vector2f(0, 0);
}

iPhysicsComponent::~iPhysicsComponent()
{
}

void iPhysicsComponent::UpdatePhysics(float dTime)
{

	m_Velocity += m_Acceleration * dTime;
	m_Position += m_Velocity * dTime;

	//increment direction and angular velocity
	m_AngularVelocity += m_AngularAcceleration * dTime;

	//For more realistic boat physics, only turn at a rate of a function of the velocity
	//Basicly, as slow speeds, turn slowly, and at high speeds turn faster
	//			+= angular velocity  * time  * sqrt(fraction of top speed that we are at {0 to 1})
	m_Angle += m_AngularVelocity * dTime * sqrt(Physics::CartesianToMagnitude(m_Velocity) * m_MoveDrag);

	//apply drag
	m_AngularVelocity -= m_TurnDrag * m_AngularVelocity * dTime;
	m_Velocity.x -= m_MoveDrag * m_Velocity.x * dTime;
	m_Velocity.y -= m_MoveDrag * m_Velocity.y * dTime;
}

sf::Vector2f Physics::PolarToCartesian(float theta, float r)
{
	return sf::Vector2f(r * cos(theta), r * sin(theta));
}

float Physics::CartesianToAngle(sf::Vector2f val)
{
	return atan2f(val.y, val.x);
}

float Physics::CartesianToMagnitude(sf::Vector2f val)
{
	return sqrt(val.x * val.x + val.y * val.y);
}

sf::Vector2f Physics::Normilise(sf::Vector2f val)
{
	float mag = sqrt(val.x * val.x + val.y * val.y);
	return sf::Vector2f(val.x / mag, val.y / mag);
}
