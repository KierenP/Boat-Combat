#pragma once
#include "SFML\System\Vector2.hpp"
#include <math.h>

/*
As this class grows, it becomes more and more technical so a quick summary below:

Acceleration = change in velocity = change in position 
Angular Acceleration = change in angular velocity = change in Angle

Drag:

The general formular is
	
	Velocity -= Drag * Velocity (the higher the velocity, the more it decreaces by)
*/

class iPhysicsComponent
{
public:
	iPhysicsComponent();
	virtual ~iPhysicsComponent();

	virtual void Update(float dTime) = 0;	//Pure virtual function

	void AddAcceleration(sf::Vector2f val) { m_Acceleration += val; }
	void AddAngularAcceleration(float val) { m_AngularAcceleration += val; }

	void SetPosition(sf::Vector2f val) { m_Position = val; }
	void SetVelocity(sf::Vector2f val) { m_Velocity = val; }
	void SetAcceleration(sf::Vector2f val) { m_Acceleration = val; }
	void SetAngle(float val) { m_Angle = val; }
	void SetAngularVelocity(float val) { m_AngularVelocity = val; }
	void SetAngularAcceleration(float val) { m_AngularAcceleration = val; }
	void SetTurnDrag(float val) { m_TurnDrag = val; }
	void SetMoveDrag(float val) { m_MoveDrag = val; }
	
	sf::Vector2f GetPosition() { return m_Position; }
	sf::Vector2f GetVelocity() { return m_Velocity; }
	sf::Vector2f GetAcceleration() { return m_Acceleration; }
	float GetAngle() { return m_Angle; }
	float GetAngularVelocity() { return m_AngularVelocity; }
	float GetAngularAcceleration() { return m_AngularAcceleration; }
	float GetTurnDrag() { return m_TurnDrag; }
	float GetMoveDrag() { return m_MoveDrag; }

protected:
	void UpdatePhysics(float dTime);

	sf::Vector2f m_Position;		//arbitrary units
	sf::Vector2f m_Velocity;		//change in arbitrary units per second
	sf::Vector2f m_Acceleration;	//change in change in arbitrary units per second per second
	
	float m_Angle;					//measured in radians!
	float m_AngularVelocity;		//radians per second
	float m_AngularAcceleration;	//radians per second per second	

	float m_TurnDrag;
	float m_MoveDrag;
};

namespace Physics
{
	//Turn polar cordinents into cartesian
	sf::Vector2f PolarToCartesian(float theta, float r);

	//Turn Cartesian to polar
	float CartesianToAngle(sf::Vector2f val);
	float CartesianToMagnitude(sf::Vector2f val);

	//Normilise the given vector
	sf::Vector2f Normilise(sf::Vector2f val);
}

