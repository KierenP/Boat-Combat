#pragma once
#include "SFML\Graphics.hpp"

/*
	Dont worry about this, its got nothing do with the boat game.
*/

class Animation : public sf::Drawable, public sf::Transformable
{
public:
	Animation();
	Animation(sf::Texture texture, std::vector<sf::VertexArray> points, float fps = 60);	//generate from texture and pre-calculated points	
	Animation(sf::Texture texture, sf::Vector2f frameDimentions, float fps = 60);			//generate from texture and dimentions of each sprite on the texture and the calculate the points
	~Animation();

	void Create(sf::Texture texture, std::vector<sf::VertexArray> points, float fps = 60);
	void Create(sf::Texture texture, sf::Vector2f frameDimentions, float fps = 60);

	void Update(float dTime);

	void AddFrame(sf::VertexArray frame);
	void RemoveFrame(unsigned int index);		//no saftey checks for out of bounds index!

	sf::Texture GetTexture();
	std::vector<sf::VertexArray> GetFrameVec();
	sf::Vector2f GetDimentions();
	float GetAnimationFPS();

	void SetTexture(sf::Texture val);
	void SetFrameVec(std::vector<sf::VertexArray> val);
	void SetDimentions(sf::Vector2f val);
	void SetAnimatonFPS(float fps);

private:
	void GenerateFrames();

	std::vector<sf::VertexArray> m_FramePoints;
	sf::Texture m_Texture;
	sf::Vector2f m_FrameDimentions;
	float m_AnimationTime; //in seconds
	float m_AnimationFPS;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;	
};

